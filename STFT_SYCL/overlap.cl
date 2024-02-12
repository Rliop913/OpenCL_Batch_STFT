//DEBUG OR RELEASE
#define DO_DEBUG


//Front declaration
//declare here, implement later






//Kernel entry point
__kernel void entry_point(__global float* frame_in, __global float2* frame_out, int window_frame,const int overlap_frame, int2 acc_able_frame, int front_side_zero_padding_size)
{

    unsigned long myid = get_global_id(0);
    unsigned long quot =myid/window_frame;

    int rem = myid % window_frame;
    unsigned long my_index = quot*overlap_frame + rem;
    float will_write;
    unsigned long frame_limit = acc_able_frame.x*window_frame + acc_able_frame.y;
    
    will_write = frame_limit<=my_index?0:frame_in[my_index];
    will_write = rem<front_side_zero_padding_size?0:will_write;

    frame_out[myid].x=will_write;
    frame_out[myid].y=0;
}






#ifndef DO_DEBUG
//Release Codes




#endif //DO_RELEASE



#ifdef DO_DEBUG
//Debug Codes





#endif //DO_DEBUG