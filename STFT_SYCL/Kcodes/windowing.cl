

inline float window_func(const int powed, const int index, const int window_size)
{
    return (0.42 - 0.5*cospi(2.0*(float)index/(float)window_size)+0.08*cospi(4.0*(float)index/(float)(window_size)));
}

__kernel void windowing(__global float2* frame_in, __global float2* frame_out, int window_radix_2_size)
{
    int powed = (int)pow(2.0,window_radix_2_size);
    long myid = get_global_id(0);
    frame_out[myid].x = frame_in[myid].x*window_func(powed,myid%powed,powed);
    
}

