//DEBUG OR RELEASE
#define DO_DEBUG


float dbfs(float powered, int window_origin_size, int added_size){
    float result = 10.0 * log10(pow(powered,2) / (1.0 * (float)window_origin_size*(float)added_size));
    
    return result;
}

__kernel void to_dbfs(__global float3* in_frame, __global float3* out_frame, int window_radix_2, int low_size, int mid_size, int high_size)
{
    long myid = get_global_id(0);
    out_frame[myid].x = dbfs(in_frame[myid].x,window_radix_2,low_size);
    out_frame[myid].y = dbfs(in_frame[myid].y,window_radix_2,mid_size);
    out_frame[myid].z = dbfs(in_frame[myid].z,window_radix_2,high_size);
    
    
}






#ifndef DO_DEBUG
//Release Codes




#endif //DO_RELEASE



#ifdef DO_DEBUG
//Debug Codes





#endif //DO_DEBUG