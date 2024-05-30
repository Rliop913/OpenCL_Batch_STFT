#pragma once
#include "cl_FACADE.h"
#include "cl_global_custom.h"
#include "cl_embedded.h"
#include <vector>
#include <memory>
#define DEFAULT_SAMPLERATE 48000
#define EQ_LOW_MID 250
#define EQ_MID_HIGH 5000
#define EQ_HIGH_TOO_HIGH 16000
#define to_big_radix_2(var) pow(2,std::ceil(log2(var)));
using error_arr = std::vector<cl_int>;
using TIDX = unsigned int;
typedef unsigned long long ma_uint64;


class OPENCL_ACC{
private:
	cl_embed *CLS;
	Kernel KO;
	Kernel KS;
	void to_dbfs(cl_float3* data, const int& window_radix_size, const int& low, const int& mid, const int& high, const int& quot );
	bool ready = false;
public:
	Platform PF;
	Device DV;
	Context CT;
	OPENCL_ACC();
	OPENCL_ACC(const std::string& platform, const std::string& device);
	~OPENCL_ACC();
	std::vector<std::pair<std::string, std::string>> get_platform_device_list();
	void set_platform_device(const std::string& platform, const std::string& device);

	float* cl_STFT(short* full_frame, const ma_uint64& full_length, const int& window_radix_2, const double& overlap_ratio, const int& both_side_z_padding_size, int& number_of_index);
};



	// template<class data_in_T, class data_out_T>
	// error_arr gpgpu_facade(
	// 	const std::string& CL_C_code, 
	// 	const std::string& CL_C_entry_name,
	// 	data_in_T*& in_data_P, 
	// 	const ma_uint64& in_data_length,
	// 	data_out_T*& out_data_P,
	// 	const ma_uint64& out_data_length,
	// 	const ma_uint64& core_size,
	// 	const extra_args& args);

#ifndef NO_EMBEDDED_CL


// template <class data_in_T, class data_out_T>
// error_arr
// OPENCL_ACC::gpgpu_facade(
// 	const std::string& CL_C_code,
// 	const std::string& CL_C_entry_name,
// 	data_in_T*& in_data_P,
// 	const ma_uint64& in_data_length,
// 	data_out_T*& out_data_P,
// 	const ma_uint64& out_data_length,
// 	const ma_uint64& core_size,
// 	const extra_args& args)
// {
	
// 	Kernel KN = cl_facade::create_kernel(CL_C_code, CL_C_entry_name, CT, DV);
// 	CommandQueue CQ = clboost::make_cq(CT, DV);

// 	Buffer data_in = clboost::make_r_buf<data_in_T>(CT, in_data_length, in_data_P);
// 	Buffer data_out = clboost::make_w_buf<data_out_T>(CT, out_data_length);
	
// 	error_arr era(args.size());
// 	int err_count = 0;
// 	int arg_set_index = 0;
// 	era[err_count++] = KN.setArg(arg_set_index++, data_in);
// 	era[err_count++] = KN.setArg(arg_set_index++, data_out);
// 	for (auto i : args){
// 		era[err_count++] = KN.setArg(arg_set_index++, i);
// 	}
// 	era[err_count++] = clboost::enq_q(CQ, KN, core_size);
// 	if (out_data_P == nullptr) {
// 		out_data_P = new data_out_T[out_data_length];
// 	}
// 	era[err_count++] = clboost::q_read<data_out_T>(CQ, data_out, true, out_data_length, out_data_P);
// 	return era;
// }
#endif // !NO_EMBEDDED_CL


#ifdef NO_EMBEDDED_CL



#endif // NO_EMBEDDED_CL