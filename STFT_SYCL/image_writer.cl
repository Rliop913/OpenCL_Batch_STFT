


inline uchar set_pixel(int index_x, int index_y, float data, int y_jump){
    if(index_y*y_jump>data){
        return 0;
    }
}


__kernel void entry_point(__global uchar *img_buffer, __global float3 *STFT_data, int width, int height, int FFT_power_limit){
    int true_index = get_global_id(0);
    int axis_x = true_index%width;
    int axis_y = true_index/width;
    int y_jump = 2*FFT_power_limit/height;
    img_buffer[myid] = (uchar)255;
    img_buffer[myid + 1] = (uchar)0;
    img_buffer[myid + 2] = (uchar)0;
    img_buffer[myid + 3] = (uchar)255;
}