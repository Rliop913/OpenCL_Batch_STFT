__kernel void entry_point(__global float* in_frame, __global float* low_out, int radix_2_half_size, int low_mid, int padded_size)
{
    long myid = get_global_id(0);
    long powed_limit = (long)pow(2.0,radix_2_half_size);
    int my_locale_index = myid % padded_size;
    int my_global_index = myid / padded_size;
    long my_index = powed_limit * my_global_index + my_locale_index;
    float for_write = my_locale_index==0||my_locale_index==1||my_locale_index>=low_mid?0:in_frame[my_index];
    low_out[myid]=for_write;
}