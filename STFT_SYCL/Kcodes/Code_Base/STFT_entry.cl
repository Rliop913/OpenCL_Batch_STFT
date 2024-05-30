#define TIDX uint
#define TIDX2 uint2
typedef struct Dvals {
    global float2* in;
    global float* out;
    TIDX full_length;
    TIDX window_length;
    TIDX idx;
    TIDX loc_idx;
}DV;

__kernel void 
overlap(__global float* in,
        __global float2* out,
        int window_frame,
        int overlap_frame, 
        TIDX frame_limit, 
        int front_side_zero_padding_size)
{
    private TIDX idx = get_global_id(0);
    private TIDX quot =idx / window_frame;

    private int rem = idx % window_frame;
    private TIDX my_index = quot * overlap_frame + rem;
    private float will_write;
    
    will_write = frame_limit <= my_index ? 0 : in[my_index];
    will_write = rem < front_side_zero_padding_size ? 0 : will_write;
    out[idx].x = will_write;
    out[idx].y = 0;
}


inline float 
window_func(const int index, const int window_size)
{
    return (0.42 - 0.5*cospi(2.0*(float)index/(float)window_size)+0.08*cospi(4.0*(float)index/(float)(window_size)));
}

void 
windowing(DV db, int window_len)
{
    db.in[db.idx].x = db.in[db.idx].x * window_func(db.idx % window_len, window_len);
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
bitreverse_stft(DV db, int window_len, int radix_2)
{
    private TIDX id_quot = db.idx / window_len;
    private int id_rem = db.idx % window_len;
    TIDX calced_id = id_quot * window_len + reverseBits(id_rem,radix_2);
    private TIDX2 tout;
    tout.x = db.in[calced_id].x;
    tout.y = 0.0;
    barrier(CLK_GLOBAL_MEM_FENCE);
    db.in[db.idx].x = tout.x;
    db.in[db.idx].y = tout.y;
    // out_frame[myid].x = frame[calced_id].x;
    // out_frame[myid].y = 0.0;

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
TIDX2 indexer(const TIDX ID,const int stage)
{
    private TIDX2 temp;
    private TIDX powed = pow(2.0, stage);
    temp.x = (ID%(powed))+powed*2*(ID/powed);
    temp.y = temp.x+powed;
    return temp;
}
void 
butterfly_stft(DV db, int radix_2, TIDX core_size)
{
    for(int stage = 0; stage < radix_2; ++stage){
        if(db.idx < (core_size / 2)){
            private TIDX powed_stage = (TIDX)pow(2.0, stage);
            private TIDX2 origin_pair=indexer(db.idx, stage);
            private cfloat this_twiddle = twiddle(db.idx % powed_stage, powed_stage * 2);
            this_twiddle = cmult(db.in[origin_pair.y],this_twiddle);
            private float2 tempx;
            private float2 tempy;
            tempx = db.in[origin_pair.x] + this_twiddle;
            tempy = db.in[origin_pair.y] - this_twiddle;
            barrier(CLK_GLOBAL_MEM_FENCE);
            db.in[origin_pair.x] = tempx;
            db.in[origin_pair.y] = tempy;
        }
        else{
            barrier(CLK_GLOBAL_MEM_FENCE);
        }
        barrier(CLK_GLOBAL_MEM_FENCE);
    }
}
#define HF_SZ(N) (N / 2)
#define IDX(C, ID) ((ID / HF_SZ(C) * C) + (ID % HF_SZ(C)))
void 
to_power(DV db, TIDX core_size)
{
    if(db.idx < core_size / 2){
        private float powered = cmod(db.in[IDX(core_size, db.idx)]);
        db.out[db.idx]= db.idx % HF_SZ(core_size) < 2 ? 0 : powered;   
    }
}

void normalization()
{

}

void DC_remover(DV db)
{
    
}


__kernel void stft_entry_function(__global float2* in_frame, __global float* out_frame, int window_size, int radix_window, TIDX core_size)
{
    private DV dv;
    dv.in = in_frame;
    dv.out = out_frame;
    dv.idx = get_global_id(0);
    dv.loc_idx = get_local_id(0);
    dv.full_length = get_global_size(0);
    dv.window_length = get_local_size(0);
    windowing(dv, window_size);
    bitreverse_stft(dv, window_size, radix_window);
    butterfly_stft(dv, radix_window, core_size);
    to_power(dv, core_size);
}
