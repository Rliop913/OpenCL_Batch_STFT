#define TIDX uint
#define TIDX2 uint2
#define FULL_LENGTH get_global_size(0)
#define WINDOW_LENGTH get_local_size(0)
#define GID get_global_id(0)
#define LID get_local_id(0)
typedef struct Dvals {
    global float2* in;
    global float* out;
}DV;

void DC_remover(__global short* in, __local atomic_int* sums)
{
    atomic_fetch_add(sums,convert_int(in[GID]));
    barrier(CLK_LOCAL_MEM_FENCE);
    in[GID] -= convert_short(atomic_load(sums)/WINDOW_LENGTH);
}


inline float 
window_func(const int index, const int window_size)
{
    return (0.42 - 0.5*cospi(2.0*(float)index/(float)window_size)+0.08*cospi(4.0*(float)index/(float)(window_size)));
}

void 
windowing(__global float2* in)
{
    in[GID].x = in[GID].x * window_func(LID, WINDOW_LENGTH);
}



inline int 
reverseBits(int num, int radix_2_data) {
    private int reversed = 0;
    for (int i = 0; i < radix_2_data; ++i) {
        reversed = (reversed << 1) | (num & 1);
        num >>= 1;
    }
    return reversed;
}

void 
bitreverse_stft(__global float2* in, int radix_2)
{
    private TIDX id_quot = GID / WINDOW_LENGTH;
    TIDX calced_id = id_quot * WINDOW_LENGTH + reverseBits(LID, radix_2);
    private TIDX2 tout;
    tout.x = in[calced_id].x;
    tout.y = 0.0;
    barrier(CLK_LOCAL_MEM_FENCE);
    in[GID].x = tout.x;
    in[GID].y = tout.y;
}
typedef float2 cfloat;

#define I ((cfloat)(0.0, 1.0))

inline float  real(cfloat a){
     return a.x;
}
inline float  imag(cfloat a){
     return a.y;
}

inline float cmod(cfloat a){
    return (sqrt(a.x*a.x + a.y*a.y));
}
inline float carg(cfloat a){
    if(a.x > 0){
        return atan(a.y / a.x);

    }else if(a.x < 0 && a.y >= 0){
        return atan(a.y / a.x) + M_PI;

    }else if(a.x < 0 && a.y < 0){
        return atan(a.y / a.x) - M_PI;

    }else if(a.x == 0 && a.y > 0){
        return M_PI/2;

    }else if(a.x == 0 && a.y < 0){
        return -M_PI/2;

    }else{
        return 0;
    }
}

inline cfloat  cmult(cfloat a, cfloat b){
    return (cfloat)( a.x*b.x - a.y*b.y, a.x*b.y + a.y*b.x);
}

inline cfloat cdiv(cfloat a, cfloat b){
    return (cfloat)((a.x*b.x + a.y*b.y)/(b.x*b.x + b.y*b.y), (a.y*b.x - a.x*b.y)/(b.x*b.x + b.y*b.y));
}
cfloat twiddle(int high, int low)
{
    cfloat temp;
    float angle = 2.0*((float)high/(float)low);
    temp.x = cospi(angle);
    temp.y = -1.0*sinpi(angle);
    return temp;
}
TIDX2 indexer(const TIDX ID,const int powed_stage)
{
    private TIDX2 temp;
    temp.x = (ID%(powed_stage))+powed_stage*2*(ID/powed_stage);
    temp.y = temp.x+powed_stage;
    return temp;
}

void 
butterfly_stft(__global float2* in, int radix_2)
{
    for(int stage = 0; stage < radix_2; ++stage){
        if(GID < (FULL_LENGTH / 2)){
            private TIDX powed_stage = (TIDX)pow(2.0, stage);
            private TIDX2 origin_pair = indexer(GID, powed_stage);
            private cfloat this_twiddle = twiddle(GID % powed_stage, powed_stage * 2);
            this_twiddle = cmult(in[origin_pair.y],this_twiddle);
            private float2 tempx;
            private float2 tempy;
            tempx = in[origin_pair.x] + this_twiddle;
            tempy = in[origin_pair.y] - this_twiddle;
            barrier(CLK_LOCAL_MEM_FENCE);
            in[origin_pair.x] = tempx;
            in[origin_pair.y] = tempy;
        }
        else{
            barrier(CLK_LOCAL_MEM_FENCE);
        }
        barrier(CLK_LOCAL_MEM_FENCE);
    }
}
#define HF_SZ(N) (N / 2)
#define IDX(C, ID) ((ID / HF_SZ(C) * C) + (ID % HF_SZ(C)))
void 
to_power(__global float2* in, __global float* out)
{
    if(GID < FULL_LENGTH / 2){
        private float powered = cmod(in[IDX(FULL_LENGTH, GID)]);
        out[GID] = powered;//GID % HF_SZ(core_size) < 2 ? 0 : powered;   
    }
}

void normalization()
{

}



__kernel void STFT( __global short* in,
                    __global float2* tempBuffer,
                    __global float* out,
                    int overlapFrame,
                    TIDX frameLimit,
                    int FrontZeroPad,
                    int windowRadix)
{
    local atomic_int dc_avg;
    atomic_init(&dc_avg, 0);
    DC_remover(in, &dc_avg);
    private TIDX quot = GID / WINDOW_LENGTH;
    private TIDX my_index = quot * overlapFrame + LID;
    private float will_write;
    
    will_write = frameLimit <= my_index ? 0 : convert_float(in[my_index]);
    will_write = LID < FrontZeroPad ? 0 : will_write;
    tempBuffer[GID].x = will_write;
    tempBuffer[GID].y = 0;
    windowing(tempBuffer);
    bitreverse_stft(tempBuffer, windowRadix);
    butterfly_stft(tempBuffer, windowRadix);
    to_power(tempBuffer, out);
}









// __kernel void 
// overlap(__global short* in,
//         __global float2* out,
//         int overlap_frame,
//         TIDX frame_limit, 
//         int front_side_zero_padding_size)
// {
//     local atomic_int dc_avg;
//     atomic_init(&dc_avg, 0);
//     DC_remover(in, &dc_avg);
//     private TIDX quot = GID / WINDOW_LENGTH;
//     private TIDX my_index = quot * overlap_frame + LID;
//     private float will_write;
    
//     will_write = frame_limit <= my_index ? 0 : convert_float(in[my_index]);
//     will_write = LID < front_side_zero_padding_size ? 0 : will_write;
//     out[GID].x = will_write;
//     out[GID].y = 0;
// }


// // __kernel void STFT(__global float2* in_frame, __global float* out_frame, int radix_window)
// // {
    
// //     windowing(in_frame);
// //     bitreverse_stft(in_frame, radix_window);
// //     butterfly_stft(in_frame, radix_window);
// //     to_power(in_frame, out_frame);
// // }