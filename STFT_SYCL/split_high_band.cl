__kernel void split_high_band(__global float* in_frame, __global float* high_out, int radix_2_half_size, int mid_high, int padded_size)
{
    long myid = get_global_id(0);
    long powed_limit = (int)pow(2.0,radix_2_half_size);
    int my_locale_index = (myid % padded_size);
    int my_global_index = myid / padded_size;
    long my_index = powed_limit*my_global_index + my_locale_index + mid_high;
    float for_write = my_locale_index>=mid_high?0:in_frame[my_index];
    high_out[myid]=for_write;
}