
__kernel void DaC(__global float* in_frame, __global float* out_frame)
{
    long myid = get_global_id(0);
    int2 my_index;
    my_index.x = (myid*2);
    my_index.y = my_index.x+1;
    out_frame[myid]= in_frame[my_index.x]+in_frame[my_index.y];
    
}