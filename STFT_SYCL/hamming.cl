//DEBUG OR RELEASE
#define DO_DEBUG


//Front declaration
//declare here, implement later


inline float window_func(const int powed, const int index, const int window_size)
{
    return (0.42 - 0.5*cos(2.0*M_PI*(float)index/(float)window_size)+0.08*cos(4.0*M_PI*(float)index/(window_size)));
}

__kernel void entry_point(__global float2* frame_in, __global float2* frame_out, int window_radix_2_size)
{
    int powed = (int)pow(2.0,window_radix_2_size);
    long myid = get_global_id(0);
    frame_out[myid].x = frame_in[myid].x*window_func(powed,myid%powed,powed);
    
}






#ifndef DO_DEBUG
//Release Codes




#endif //DO_RELEASE



#ifdef DO_DEBUG
//Debug Codes





#endif //DO_DEBUG