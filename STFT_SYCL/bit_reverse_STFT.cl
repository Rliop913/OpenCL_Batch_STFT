//DEBUG OR RELEASE
#define DO_DEBUG


//Front declaration
//declare here, implement later



int reverseBits(int num, int radix_2_data) {
    int reversed = 0;
    for (int i = 0; i < radix_2_data; ++i) {
        reversed = (reversed << 1) | (num & 1);
        num >>= 1;
    }
    return reversed;
}
__kernel void bitreverse_stft(__global float2* frame, __global float2* out_frame, int radix_2)
{
    int powed = (int)pow(2.0,radix_2);
    long myid = get_global_id(0);
    long id_quot = myid / powed;
    int id_rem = myid%powed;
    long calced_id = id_quot*powed + reverseBits(id_rem,radix_2);
    out_frame[myid].x = frame[calced_id].x;
    out_frame[myid].y = 0.0;

}






#ifndef DO_DEBUG
//Release Codes




#endif //DO_RELEASE



#ifdef DO_DEBUG
//Debug Codes





#endif //DO_DEBUG