#include "STFT.h"

std::vector<std::pair<std::string, std::string>>
OPENCL_ACC::get_platform_device_list()
{
    std::vector<std::pair<std::string, std::string>> pla_dev;
    std::vector<Platform> pvec;
    Platform::get(&pvec);
    for (int i = 0; i < pvec.size(); ++i) {
        std::string pname;
        std::vector<Device> dvec;
        pvec[i].getInfo(CL_PLATFORM_NAME, &pname);
        pvec[i].getDevices(CL_DEVICE_TYPE_ALL, &dvec);
        for (int j = 0; j < dvec.size(); ++j) {
            std::pair<std::string, std::string> dpair;
            std::string dname;
            dvec[j].getInfo(CL_DEVICE_NAME, &dname);
            dpair.first = pname;
            dpair.second = dname;
            pla_dev.push_back(dpair);
        }
    }
    return pla_dev;
}
void
OPENCL_ACC::set_platform_device(const std::string& platform, const std::string& device)
{
    std::vector<Platform> pvec;
    Platform::get(&pvec);
    for (int i = 0; i < pvec.size(); ++i) {
        std::string pname;
        pvec[i].getInfo(CL_PLATFORM_NAME, &pname);
        
        if (pname == platform) {
            this->PF = pvec[i];
            break;
        }
    }
    std::vector<Device> dvec;
    this->PF.getDevices(CL_DEVICE_TYPE_ALL, &dvec);
    for (int i = 0; i < dvec.size(); ++i) {
        std::string dname;
        dvec[i].getInfo(CL_DEVICE_NAME, &dname);
        if (dname == device) {
            this->DV = dvec[i];
            
            break;
        }
    }
    this->CT = Context(this->DV);
    this->ready = true;
    KO = cl_facade::create_kernel(CLS->STFT, "overlap", CT, DV);
    KS = cl_facade::create_kernel(CLS->STFT, "STFT", CT, DV);

}


OPENCL_ACC::OPENCL_ACC(const std::string& platform, const std::string& device)
{
    CLS = new cl_embed();
    set_platform_device(platform, device);
}
OPENCL_ACC::OPENCL_ACC() {
    CLS = new cl_embed();
}
OPENCL_ACC::~OPENCL_ACC() {
    delete CLS;
}








#include <iostream>
#include <fstream>
float*
OPENCL_ACC::cl_STFT(short* full_frame, const ma_uint64& origin_len, const int& window_radix_2, const double& overlap_ratio, const int& front_side_z_padding_size, int& number_of_index)
{

    
    int window_len = pow(2, (int)window_radix_2);
    int overlaped_frame = (1.0 - overlap_ratio) * window_len;
    int fft_quotient = origin_len / (int)((double)window_len * (1.0 - overlap_ratio));
    cl_uint overlaped_full_frame = fft_quotient * window_len;
    cl_float2* temp_buffer = nullptr;


	CommandQueue CO = clboost::make_cq(CT, DV);

	Buffer oin = clboost::make_r_buf<short>(CT, origin_len, full_frame);
	Buffer oout = clboost::make_w_buf<cl_float2>(CT, overlaped_full_frame);
	
	error_arr era(8);
	int err_count = 0;
	era[err_count++] = KO.setArg(0, oin);
	era[err_count++] = KO.setArg(1, oout);
    era[err_count++] = KO.setArg(2, overlaped_frame);
    era[err_count++] = KO.setArg(3, (unsigned int)origin_len);
    era[err_count++] = KO.setArg(4, front_side_z_padding_size);
    
	era[err_count++] = clboost::enq_q(CO, KO, overlaped_full_frame, window_len);
	if (temp_buffer == nullptr) {
		temp_buffer = new cl_float2[overlaped_full_frame];
	}
	era[err_count++] = clboost::q_read<cl_float2>(CO, oout, true, overlaped_full_frame, temp_buffer);

    float * out_stft = nullptr;

	CommandQueue CQ = clboost::make_cq(CT, DV);

	Buffer data_in = clboost::make_r_buf<cl_float2>(CT, overlaped_full_frame, temp_buffer);
	Buffer data_out = clboost::make_w_buf<float>(CT, overlaped_full_frame/2);
	int temp1 = KS.setArg(0, data_in);
	int temp2 = KS.setArg(1, data_out);
    int temp4 = KS.setArg(2, window_radix_2);
	int temp6 = clboost::enq_q(CQ, KS, overlaped_full_frame,window_len);
	if (out_stft == nullptr) {
		out_stft = new float[overlaped_full_frame/2];
	}
	int temp7 = clboost::q_read<float>(CQ, data_out, true, overlaped_full_frame/2, out_stft);
	delete[](temp_buffer);










    std::ofstream out("stft_out.csv");
    for(int i =0;i<fft_quotient;++i){
        for(int j=0;j<window_len/2;++j){
            out << out_stft[(window_len/2)*i+j] << ",";

        }
        out << "\n";
    }
    out.close();
    return out_stft;
}




// void
// OPENCL_ACC::to_dbfs(cl_float3* data, const int& window_radix_size, const int& low, const int& mid, const int& high, const int& quot )
// {
//     // int wos = pow(2, window_radix_size);
//     // gpgpu_facade<cl_float3, cl_float3>(
//     //     CLS->to_dbfs,
//     //     "to_dbfs",
//     //     data,
//     //     quot,
//     //     data,
//     //     quot,
//     //     quot,
//     //     wos,
//     //     low,
//     //     mid,
//     //     high
//     // );
    
// }













#include "miniaudio.h"
#include <fstream>
//
#include <iostream>
int main() {
        OPENCL_ACC oa = OPENCL_ACC();
    std::vector<std::pair<std::string, std::string>> list = oa.get_platform_device_list();
    /*for(int i = 0; i < list.size(); ++i) {
        std::cout << list[i].first << "--" << list[i].second << std::endl;
    }*/
    oa.set_platform_device(
        "NVIDIA CUDA", "NVIDIA GeForce GTX 1660 Ti with Max-Q Design");//�ӽ÷� �ϵ��ڵ�

    //oa.STFT_TESTER();
    int radix = 10;

    ma_decoder_config deconf = ma_decoder_config_init(ma_format_s16, 1, 48000);
    ma_decoder dec;
    std::cout<<ma_decoder_init_file("G://RAS.wav", &deconf, &dec);
    ma_uint64 length = 48000;
    ma_decoder_get_length_in_pcm_frames(&dec, &length);
    length/=200;
    // ma_waveform_config config = ma_waveform_config_init(
    //     ma_format_f32,
    //     1,
    //     48000,
    //     ma_waveform_type_sine,
    //     1.0,
    //     23000.0);

    // ma_waveform waveform;
    // ma_result result = ma_waveform_init(&config, &waveform);
    // if (result != MA_SUCCESS) {
    //     // Error.
    // }

    //int leng = 48000;
    short *data = new short[length];
    // ma_waveform_read_pcm_frames(&waveform, data, leng, NULL);
    //length /= 5;
    //float* full_frame = new float[length];
    ma_uint64 check;
    ma_decoder_read_pcm_frames(&dec, data, length, NULL);
    //ma_decoder_read_pcm_frames(&dec, full_frame, length, &check);
    //ASSERT_EQ(check, length);
    int quot = 0;
    int low = 0;
    int mid = 0;
    int high = 0;
    int pow_half = pow(2, radix - 1);
    // for(int i=0; i<length;++i){
    //     std::cout<<data[i]<<"``";
    // }
    float* stft_output = oa.cl_STFT(data, length, radix, 0.5, 512, quot);
    
    //cl_float3* tband = oa.three_bander(stft_output, radix, low, mid, high, quot);
    //oa.to_dbfs(tband, radix, low, mid, high, quot);
    /*for (int j = 0; j < leng; ++j) {
        if (j % pow_half == 0) {
            std::cout << std::endl;
        }
        std::cout << stft_output[j] << ",";

    }*/
    // for (int j = 0; j < leng; ++j) {
    //     std::cout<< data[leng] << "-";
    // }
    // for (int i = 0; i < pow(2,radix)*3; ++i) {
    //     std::cout << stft_output[i] << ",";
    // }
    
    /*for (int i = 0; i < quot; ++i) {
        std::cout << tband[i].x << "," << tband[i].y << "," << tband[i].z << std::endl;
    }*/
    /*std::cout << std::endl;
    std::vector<complex<double>> temp_vec;
    for (int i = 0; i < leng; ++i) {
        temp_vec.push_back(data[i]);
    }
    int i = 0;*/
    /*std::vector<complex<double>> dft_out = DFT(temp_vec);
    for (complex<double> dd : dft_out) {
        std::cout << stft_output[i] << "," << sqrt(pow(2.0, dd.real()) + pow(2.0, dd.imag())) << std::endl;
        ++i;
        if (i >= leng) {
            break;
        }

    }*/
    /*for (int i = 0; i < quot; ++i) {
        std::cout << tband[i].x << "," << tband[i].y << "," << tband[i].z << std::endl;
    }*/
    //getchar();



    return 0;
}


