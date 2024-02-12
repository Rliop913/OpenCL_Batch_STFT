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


//Kernel entry point
__kernel void entry_point(__global float* frame, __global float2* out_frame, int radix_2)
{
    long myid = get_global_id(0);
    out_frame[myid].x = frame[reverseBits(myid,radix_2)];
    out_frame[myid].y = 0.0;

}






#ifndef DO_DEBUG
//Release Codes




#endif //DO_RELEASE



#ifdef DO_DEBUG
//Debug Codes





#endif //DO_DEBUG