//DEBUG OR RELEASE
#define DO_DEBUG


//Front declaration
//declare here, implement later


inline float cmod(float2 a){
    return (sqrt(a.x*a.x + a.y*a.y));
}
__kernel void entry_point(__global float2* in_frame, __global float* out_frame, int origin_size)
{
    long myid = get_global_id(0);
    long half_size = (long)origin_size / 2;
    long index = ((long)origin_size * ( myid / half_size )) + ( myid % half_size );
    out_frame[myid]=cmod(in_frame[index]);
    
    
}






#ifndef DO_DEBUG
//Release Codes




#endif //DO_RELEASE



#ifdef DO_DEBUG
//Debug Codes





#endif //DO_DEBUG