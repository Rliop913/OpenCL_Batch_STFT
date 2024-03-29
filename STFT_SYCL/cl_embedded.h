
#pragma once
//generated with python code
#include <string>
class cl_embed {
    public:
    #ifndef NO_EMBEDDED_CL
std::string bitreverse = 
	"//DEBUG OR RELEASE\n"
	"#define DO_DEBUG\n"
	"\n"
	"\n"
	"//Front declaration\n"
	"//declare here, implement later\n"
	"\n"
	"\n"
	"\n"
	"int reverseBits(int num, int radix_2_data) {\n"
	"    int reversed = 0;\n"
	"    for (int i = 0; i < radix_2_data; ++i) {\n"
	"        reversed = (reversed << 1) | (num & 1);\n"
	"        num >>= 1;\n"
	"    }\n"
	"    return reversed;\n"
	"}\n"
	"\n"
	"\n"
	"//Kernel entry point\n"
	"__kernel void bitreverse(__global float* frame, __global float2* out_frame, int radix_2)\n"
	"{\n"
	"    long myid = get_global_id(0);\n"
	"    out_frame[myid].x = frame[reverseBits(myid,radix_2)];\n"
	"    out_frame[myid].y = 0.0;\n"
	"\n"
	"}\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"#ifndef DO_DEBUG\n"
	"//Release Codes\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"#endif //DO_RELEASE\n"
	"\n"
	"\n"
	"\n"
	"#ifdef DO_DEBUG\n"
	"//Debug Codes\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"#endif //DO_DEBUG\n"
	;
#endif
#ifdef NO_EMBEDDED_CL
std::string bitreverse = 
	"CL_C_kernel_files/bit_reverse.cl\n"
	;
#endif
#ifndef NO_EMBEDDED_CL
std::string bitreverse_stft = 
	"//DEBUG OR RELEASE\n"
	"#define DO_DEBUG\n"
	"\n"
	"\n"
	"//Front declaration\n"
	"//declare here, implement later\n"
	"\n"
	"\n"
	"\n"
	"int reverseBits(int num, int radix_2_data) {\n"
	"    int reversed = 0;\n"
	"    for (int i = 0; i < radix_2_data; ++i) {\n"
	"        reversed = (reversed << 1) | (num & 1);\n"
	"        num >>= 1;\n"
	"    }\n"
	"    return reversed;\n"
	"}\n"
	"__kernel void bitreverse_stft(__global float2* frame, __global float2* out_frame, int radix_2)\n"
	"{\n"
	"    int powed = (int)pow(2.0,radix_2);\n"
	"    long myid = get_global_id(0);\n"
	"    long id_quot = myid / powed;\n"
	"    int id_rem = myid%powed;\n"
	"    long calced_id = id_quot*powed + reverseBits(id_rem,radix_2);\n"
	"    out_frame[myid].x = frame[calced_id].x;\n"
	"    out_frame[myid].y = 0.0;\n"
	"\n"
	"}\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"#ifndef DO_DEBUG\n"
	"//Release Codes\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"#endif //DO_RELEASE\n"
	"\n"
	"\n"
	"\n"
	"#ifdef DO_DEBUG\n"
	"//Debug Codes\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"#endif //DO_DEBUG\n"
	;
#endif
#ifdef NO_EMBEDDED_CL
std::string bitreverse_stft = 
	"CL_C_kernel_files/bit_reverse_STFT.cl\n"
	;
#endif
#ifndef NO_EMBEDDED_CL
std::string butterfly = 
	"typedef float2 cfloat;\n"
	"#define I ((cfloat)(0.0, 1.0))\n"
	"inline float  real(cfloat a){\n"
	"     return a.x;\n"
	"}\n"
	"inline float  imag(cfloat a){\n"
	"     return a.y;\n"
	"}\n"
	"inline float cmod(cfloat a){\n"
	"    return (sqrt(a.x*a.x + a.y*a.y));\n"
	"}\n"
	"inline float carg(cfloat a){\n"
	"    if(a.x > 0){\n"
	"        return atan(a.y / a.x);\n"
	"\n"
	"    }else if(a.x < 0 && a.y >= 0){\n"
	"        return atan(a.y / a.x) + M_PI;\n"
	"\n"
	"    }else if(a.x < 0 && a.y < 0){\n"
	"        return atan(a.y / a.x) - M_PI;\n"
	"\n"
	"    }else if(a.x == 0 && a.y > 0){\n"
	"        return M_PI/2;\n"
	"\n"
	"    }else if(a.x == 0 && a.y < 0){\n"
	"        return -M_PI/2;\n"
	"\n"
	"    }else{\n"
	"        return 0;\n"
	"    }\n"
	"}\n"
	"\n"
	"\n"
	"inline cfloat  cmult(cfloat a, cfloat b){\n"
	"    return (cfloat)( a.x*b.x - a.y*b.y, a.x*b.y + a.y*b.x);\n"
	"}\n"
	"\n"
	"\n"
	"inline cfloat cdiv(cfloat a, cfloat b){\n"
	"    return (cfloat)((a.x*b.x + a.y*b.y)/(b.x*b.x + b.y*b.y), (a.y*b.x - a.x*b.y)/(b.x*b.x + b.y*b.y));\n"
	"}\n"
	"\n"
	"\n"
	"cfloat twiddle(int high, int low)\n"
	"{\n"
	"    cfloat temp;\n"
	"    temp.x = cos(2.0*M_PI*((float)high/(float)low));\n"
	"    temp.y = -1.0*sin(2.0*M_PI*((float)high/(float)low));\n"
	"    return temp;\n"
	"}\n"
	"\n"
	"\n"
	"long2 indexer(const long ID,const int stage)\n"
	"{\n"
	"    long2 temp;\n"
	"    temp.x = (ID%((long)pow(2.0,stage)))+(long)pow(2.0,stage+1)*(ID/(long)pow(2.0,stage));\n"
	"    temp.y = temp.x+(long)pow(2.0,stage);\n"
	"    return temp;\n"
	"}\n"
	"__kernel void butterfly(__global float2* in_frame, __global float2* out_frame, int radix_2, int stage)\n"
	"{\n"
	"    long powed_stage = (long)pow(2.0,stage);\n"
	"    long myid = get_global_id(0);\n"
	"    long2 origin_pair=indexer(myid,stage);\n"
	"    cfloat this_twiddle = twiddle(myid%powed_stage,powed_stage*2);\n"
	"    this_twiddle = cmult(in_frame[origin_pair.y],this_twiddle);\n"
	"    out_frame[origin_pair.x]=in_frame[origin_pair.x]+this_twiddle;\n"
	"    out_frame[origin_pair.y]=in_frame[origin_pair.x]-this_twiddle;\n"
	"}\n"
	"\n"
	"\n"
	;
#endif
#ifdef NO_EMBEDDED_CL
std::string butterfly = 
	"CL_C_kernel_files/butterfly_stage.cl\n"
	;
#endif
#ifndef NO_EMBEDDED_CL
std::string butterfly_stft = 
	"\n"
	"//2 component vector to hold the real and imaginary parts of a complex number:\n"
	"typedef float2 cfloat;\n"
	"\n"
	"#define I ((cfloat)(0.0, 1.0))\n"
	"\n"
	"\n"
	"/*\n"
	" * Return Real (Imaginary) component of complex number:\n"
	" */\n"
	"inline float  real(cfloat a){\n"
	"     return a.x;\n"
	"}\n"
	"inline float  imag(cfloat a){\n"
	"     return a.y;\n"
	"}\n"
	"\n"
	"/*\n"
	" * Get the modulus of a complex number (its length):\n"
	" */\n"
	"inline float cmod(cfloat a){\n"
	"    return (sqrt(a.x*a.x + a.y*a.y));\n"
	"}\n"
	"\n"
	"/*\n"
	" * Get the argument of a complex number (its angle):\n"
	" * http://en.wikipedia.org/wiki/Complex_number#Absolute_value_and_argument\n"
	" */\n"
	"inline float carg(cfloat a){\n"
	"    if(a.x > 0){\n"
	"        return atan(a.y / a.x);\n"
	"\n"
	"    }else if(a.x < 0 && a.y >= 0){\n"
	"        return atan(a.y / a.x) + M_PI;\n"
	"\n"
	"    }else if(a.x < 0 && a.y < 0){\n"
	"        return atan(a.y / a.x) - M_PI;\n"
	"\n"
	"    }else if(a.x == 0 && a.y > 0){\n"
	"        return M_PI/2;\n"
	"\n"
	"    }else if(a.x == 0 && a.y < 0){\n"
	"        return -M_PI/2;\n"
	"\n"
	"    }else{\n"
	"        return 0;\n"
	"    }\n"
	"}\n"
	"\n"
	"/*\n"
	" * Multiply two complex numbers:\n"
	" *\n"
	" *  a = (aReal + I*aImag)\n"
	" *  b = (bReal + I*bImag)\n"
	" *  a * b = (aReal + I*aImag) * (bReal + I*bImag)\n"
	" *        = aReal*bReal +I*aReal*bImag +I*aImag*bReal +I^2*aImag*bImag\n"
	" *        = (aReal*bReal - aImag*bImag) + I*(aReal*bImag + aImag*bReal)\n"
	" */\n"
	"inline cfloat  cmult(cfloat a, cfloat b){\n"
	"    return (cfloat)( a.x*b.x - a.y*b.y, a.x*b.y + a.y*b.x);\n"
	"}\n"
	"\n"
	"\n"
	"/*\n"
	" * Divide two complex numbers:\n"
	" *\n"
	" *  aReal + I*aImag     (aReal + I*aImag) * (bReal - I*bImag)\n"
	" * ----------------- = ---------------------------------------\n"
	" *  bReal + I*bImag     (bReal + I*bImag) * (bReal - I*bImag)\n"
	" * \n"
	" *        aReal*bReal - I*aReal*bImag + I*aImag*bReal - I^2*aImag*bImag\n"
	" *     = ---------------------------------------------------------------\n"
	" *            bReal^2 - I*bReal*bImag + I*bImag*bReal  -I^2*bImag^2\n"
	" * \n"
	" *        aReal*bReal + aImag*bImag         aImag*bReal - Real*bImag \n"
	" *     = ---------------------------- + I* --------------------------\n"
	" *            bReal^2 + bImag^2                bReal^2 + bImag^2\n"
	" * \n"
	" */\n"
	"inline cfloat cdiv(cfloat a, cfloat b){\n"
	"    return (cfloat)((a.x*b.x + a.y*b.y)/(b.x*b.x + b.y*b.y), (a.y*b.x - a.x*b.y)/(b.x*b.x + b.y*b.y));\n"
	"}\n"
	"\n"
	"\n"
	"cfloat twiddle(int high, int low)\n"
	"{\n"
	"    cfloat temp;\n"
	"    float angle = 2.0*((float)high/(float)low);\n"
	"    temp.x = cospi(angle);\n"
	"    temp.y = -1.0*sinpi(angle);\n"
	"    return temp;\n"
	"}\n"
	"\n"
	"long2 indexer(const long ID,const int stage)\n"
	"{\n"
	"    long2 temp;\n"
	"    long powed = pow(2.0, stage);\n"
	"    temp.x = (ID%(powed))+powed*2*(ID/powed);\n"
	"    temp.y = temp.x+powed;\n"
	"    return temp;\n"
	"}\n"
	"\n"
	"\n"
	"__kernel void butterfly_stft(__global float2* in_frame, __global float2* out_frame, int radix_2, int stage)\n"
	"{\n"
	"    long powed_stage = (long)pow(2.0,stage);\n"
	"    long myid = get_global_id(0);\n"
	"    long2 origin_pair=indexer(myid,stage);\n"
	"    cfloat this_twiddle = twiddle(myid%powed_stage,powed_stage*2);\n"
	"    this_twiddle = cmult(in_frame[origin_pair.y],this_twiddle);\n"
	"    out_frame[origin_pair.x]=in_frame[origin_pair.x]+this_twiddle;\n"
	"    out_frame[origin_pair.y]=in_frame[origin_pair.x]-this_twiddle;\n"
	"    \n"
	"}\n"
	"\n"
	"\n"
	"\n"
	"\n"
	;
#endif
#ifdef NO_EMBEDDED_CL
std::string butterfly_stft = 
	"CL_C_kernel_files/butterfly_STFT.cl\n"
	;
#endif
#ifndef NO_EMBEDDED_CL
std::string DaC = 
	"\n"
	"__kernel void DaC(__global float* in_frame, __global float* out_frame)\n"
	"{\n"
	"    long myid = get_global_id(0);\n"
	"    int2 my_index;\n"
	"    my_index.x = (myid*2);\n"
	"    my_index.y = my_index.x+1;\n"
	"    out_frame[myid]= in_frame[my_index.x]+in_frame[my_index.y];\n"
	"    \n"
	"}\n"
	;
#endif
#ifdef NO_EMBEDDED_CL
std::string DaC = 
	"CL_C_kernel_files/DaC.cl\n"
	;
#endif
#ifndef NO_EMBEDDED_CL
std::string entry_point = 
	"\n"
	"\n"
	"\n"
	"inline uchar set_pixel(int index_x, int index_y, float data, int y_jump){\n"
	"    if(index_y*y_jump>data){\n"
	"        return 0;\n"
	"    }\n"
	"}\n"
	"\n"
	"\n"
	"__kernel void entry_point(__global uchar *img_buffer, __global float3 *STFT_data, int width, int height, int FFT_power_limit){\n"
	"    int true_index = get_global_id(0);\n"
	"    int axis_x = true_index%width;\n"
	"    int axis_y = true_index/width;\n"
	"    int y_jump = 2*FFT_power_limit/height;\n"
	"    img_buffer[myid] = (uchar)255;\n"
	"    img_buffer[myid + 1] = (uchar)0;\n"
	"    img_buffer[myid + 2] = (uchar)0;\n"
	"    img_buffer[myid + 3] = (uchar)255;\n"
	"}\n"
	;
#endif
#ifdef NO_EMBEDDED_CL
std::string entry_point = 
	"CL_C_kernel_files/image_writer.cl\n"
	;
#endif
#ifndef NO_EMBEDDED_CL
std::string integ_DaC = 
	"//DEBUG OR RELEASE\n"
	"#define DO_DEBUG\n"
	"\n"
	"\n"
	"//Front declaration\n"
	"//declare here, implement later\n"
	"\n"
	"\n"
	"//Kernel entry point\n"
	"__kernel void integ_DaC(__global float* low_in, __global float* mid_in, __global float* high_in, __global float3* integ_out)\n"
	"{\n"
	"    long myid = get_global_id(0);\n"
	"    integ_out[myid].x=low_in[myid];\n"
	"    integ_out[myid].y=mid_in[myid];\n"
	"    integ_out[myid].z=high_in[myid];\n"
	"}\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"#ifndef DO_DEBUG\n"
	"//Release Codes\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"#endif //DO_RELEASE\n"
	"\n"
	"\n"
	"\n"
	"#ifdef DO_DEBUG\n"
	"//Debug Codes\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"#endif //DO_DEBUG\n"
	;
#endif
#ifdef NO_EMBEDDED_CL
std::string integ_DaC = 
	"CL_C_kernel_files/integrate_DaC.cl\n"
	;
#endif
#ifndef NO_EMBEDDED_CL
std::string overlap = 
	"//DEBUG OR RELEASE\n"
	"#define DO_DEBUG\n"
	"\n"
	"\n"
	"//Front declaration\n"
	"//declare here, implement later\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"//Kernel entry point\n"
	"__kernel void overlap(__global float* frame_in, __global float2* frame_out, int window_frame,const int overlap_frame, int2 acc_able_frame, int front_side_zero_padding_size)\n"
	"{\n"
	"\n"
	"    unsigned long myid = get_global_id(0);\n"
	"    unsigned long quot =myid/window_frame;\n"
	"\n"
	"    int rem = myid % window_frame;\n"
	"    unsigned long my_index = quot*overlap_frame + rem;\n"
	"    float will_write;\n"
	"    unsigned long frame_limit = acc_able_frame.x*window_frame + acc_able_frame.y;\n"
	"    \n"
	"    will_write = frame_limit<=my_index?0:frame_in[my_index];\n"
	"    will_write = rem<front_side_zero_padding_size?0:will_write;\n"
	"\n"
	"    frame_out[myid].x=will_write;\n"
	"    frame_out[myid].y=0;\n"
	"}\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"#ifndef DO_DEBUG\n"
	"//Release Codes\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"#endif //DO_RELEASE\n"
	"\n"
	"\n"
	"\n"
	"#ifdef DO_DEBUG\n"
	"//Debug Codes\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"#endif //DO_DEBUG\n"
	;
#endif
#ifdef NO_EMBEDDED_CL
std::string overlap = 
	"CL_C_kernel_files/overlap.cl\n"
	;
#endif
#ifndef NO_EMBEDDED_CL
std::string split_high_band = 
	"__kernel void split_high_band(__global float* in_frame, __global float* high_out, int radix_2_half_size, int mid_high, int padded_size)\n"
	"{\n"
	"    long myid = get_global_id(0);\n"
	"    long powed_limit = (int)pow(2.0,radix_2_half_size);\n"
	"    int my_locale_index = (myid % padded_size);\n"
	"    int my_global_index = myid / padded_size;\n"
	"    long my_index = powed_limit*my_global_index + my_locale_index + mid_high;\n"
	"    float for_write = my_locale_index>=mid_high?0:in_frame[my_index];\n"
	"    high_out[myid]=for_write;\n"
	"}\n"
	;
#endif
#ifdef NO_EMBEDDED_CL
std::string split_high_band = 
	"CL_C_kernel_files/split_high_band.cl\n"
	;
#endif
#ifndef NO_EMBEDDED_CL
std::string split_low_band = 
	"__kernel void split_low_band(__global float* in_frame, __global float* low_out, int radix_2_half_size, int low_mid, int padded_size)\n"
	"{\n"
	"    long myid = get_global_id(0);\n"
	"    long powed_limit = (long)pow(2.0,radix_2_half_size);\n"
	"    int my_locale_index = myid % padded_size;\n"
	"    int my_global_index = myid / padded_size;\n"
	"    long my_index = powed_limit * my_global_index + my_locale_index;\n"
	"    float for_write = my_locale_index>=low_mid?0.0:in_frame[my_index];\n"
	"    low_out[myid]=for_write;\n"
	"}\n"
	;
#endif
#ifdef NO_EMBEDDED_CL
std::string split_low_band = 
	"CL_C_kernel_files/split_low_band.cl\n"
	;
#endif
#ifndef NO_EMBEDDED_CL
std::string split_mid_band = 
	"__kernel void split_mid_band(__global float* in_frame, __global float* mid_out, int radix_2_half_size, int low_mid, int mid_high, int padded_size)\n"
	"{\n"
	"    long myid = get_global_id(0);\n"
	"    long powed_limit = (int)pow(2.0,radix_2_half_size);\n"
	"    int my_locale_index = (myid % padded_size);\n"
	"    int my_global_index = myid / padded_size;\n"
	"    long my_index = powed_limit*my_global_index + my_locale_index + low_mid;\n"
	"    float for_write = my_locale_index>=(mid_high-low_mid)?0:in_frame[my_index];\n"
	"    mid_out[myid]=for_write;\n"
	"}\n"
	;
#endif
#ifdef NO_EMBEDDED_CL
std::string split_mid_band = 
	"CL_C_kernel_files/split_mid_band.cl\n"
	;
#endif
#ifndef NO_EMBEDDED_CL
std::string to_dbfs = 
	"//DEBUG OR RELEASE\n"
	"#define DO_DEBUG\n"
	"\n"
	"\n"
	"float dbfs(float powered, int window_origin_size, int added_size){\n"
	"    float result = 10.0 * log10(pow(powered,2) / (1.0 * (float)window_origin_size*(float)added_size));\n"
	"    \n"
	"    return result;\n"
	"}\n"
	"\n"
	"__kernel void to_dbfs(__global float3* in_frame, __global float3* out_frame, int window_radix_2, int low_size, int mid_size, int high_size)\n"
	"{\n"
	"    long myid = get_global_id(0);\n"
	"    out_frame[myid].x = dbfs(in_frame[myid].x,window_radix_2,low_size);\n"
	"    out_frame[myid].y = dbfs(in_frame[myid].y,window_radix_2,mid_size);\n"
	"    out_frame[myid].z = dbfs(in_frame[myid].z,window_radix_2,high_size);\n"
	"    \n"
	"    \n"
	"}\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"#ifndef DO_DEBUG\n"
	"//Release Codes\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"#endif //DO_RELEASE\n"
	"\n"
	"\n"
	"\n"
	"#ifdef DO_DEBUG\n"
	"//Debug Codes\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"#endif //DO_DEBUG\n"
	;
#endif
#ifdef NO_EMBEDDED_CL
std::string to_dbfs = 
	"CL_C_kernel_files/to_dbfs.cl\n"
	;
#endif
#ifndef NO_EMBEDDED_CL
std::string to_power = 
	"//DEBUG OR RELEASE\n"
	"#define DO_DEBUG\n"
	"\n"
	"\n"
	"// inline float dbfs(float powered, int window_origin_size){\n"
	"//     float result = 10 * log10(pow(powered,2) / (1.0 * window_origin_size));\n"
	"//     return result;\n"
	"// }\n"
	"\n"
	"//Front declaration\n"
	"//declare here, implement later\n"
	"\n"
	"\n"
	"inline float cmod(float2 a){\n"
	"    return (sqrt(a.x*a.x + a.y*a.y));\n"
	"}\n"
	"\n"
	"__kernel void to_power(__global float2* in_frame, __global float* out_frame, int origin_size)\n"
	"{\n"
	"    long myid = get_global_id(0);\n"
	"    long half_size = (long)origin_size / 2;\n"
	"    long index = ((long)origin_size * ( myid / half_size )) + ( myid % half_size );\n"
	"    float powered =cmod(in_frame[index]);\n"
	"    powered = myid%half_size < 2?0:powered;\n"
	"    out_frame[myid]=powered;\n"
	"    \n"
	"    \n"
	"}\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"#ifndef DO_DEBUG\n"
	"//Release Codes\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"#endif //DO_RELEASE\n"
	"\n"
	"\n"
	"\n"
	"#ifdef DO_DEBUG\n"
	"//Debug Codes\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"\n"
	"#endif //DO_DEBUG\n"
	;
#endif
#ifdef NO_EMBEDDED_CL
std::string to_power = 
	"CL_C_kernel_files/to_power.cl\n"
	;
#endif
#ifndef NO_EMBEDDED_CL
std::string windowing = 
	"\n"
	"\n"
	"inline float window_func(const int powed, const int index, const int window_size)\n"
	"{\n"
	"    return (0.42 - 0.5*cospi(2.0*(float)index/(float)window_size)+0.08*cospi(4.0*(float)index/(float)(window_size)));\n"
	"}\n"
	"\n"
	"__kernel void windowing(__global float2* frame_in, __global float2* frame_out, int window_radix_2_size)\n"
	"{\n"
	"    int powed = (int)pow(2.0,window_radix_2_size);\n"
	"    long myid = get_global_id(0);\n"
	"    frame_out[myid].x = frame_in[myid].x*window_func(powed,myid%powed,powed);\n"
	"    \n"
	"}\n"
	"\n"
	;
#endif
#ifdef NO_EMBEDDED_CL
std::string windowing = 
	"CL_C_kernel_files/windowing.cl\n"
	;
#endif

};