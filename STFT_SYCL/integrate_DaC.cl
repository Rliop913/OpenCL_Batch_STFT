//DEBUG OR RELEASE
#define DO_DEBUG


//Front declaration
//declare here, implement later


//Kernel entry point
__kernel void entry_point(__global float* low_in, __global float* mid_in, __global float* high_in, __global float3* integ_out)
{
    long myid = get_global_id(0);
    integ_out[myid].x=low_in[myid];
    integ_out[myid].y=mid_in[myid];
    integ_out[myid].z=high_in[myid];
}






#ifndef DO_DEBUG
//Release Codes




#endif //DO_RELEASE



#ifdef DO_DEBUG
//Debug Codes





#endif //DO_DEBUG