
__kernel void entry_point(__global float* in_frame, __global float* out_frame, int index_limit)
{
    long myid = get_global_id(0);
    int2 my_index;
    my_index.x = (myid*2);// % index_limit;
    my_index.y = my_index.x+1;
    float zero_or_data = my_index.y<index_limit?in_frame[my_index.y]:0;
    out_frame[myid]= in_frame[my_index.x]+zero_or_data;
}