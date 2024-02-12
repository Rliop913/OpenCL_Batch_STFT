#include "pch.h"
#include "CppUnitTest.h"
#define ON_UNIT_TEST
#include "STFT.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#define TD_OVER 10000
int reverseBits(int num, int radix_2_data) {
	    int reversed = 0;
	    for (int i = 0; i < radix_2_data; ++i) {
	        reversed = (reversed << 1) | (num & 1);
	        num >>= 1;
	    }
	    return reversed;
	}
namespace CLTester
{
	TEST_CLASS(CLTester)
	{
	public:
		
		TEST_METHOD(overlap_tester)
		{
			OPENCL_ACC oa = OPENCL_ACC("NVIDIA CUDA", "NVIDIA GeForce GTX 1660 Ti with Max-Q Design");
			int powed_radix = pow(2, 10);
			int fft_quotient = TD_OVER / (powed_radix / 2);
			ma_uint64 overlaped_full_frame = fft_quotient * powed_radix;

			float* TD_SET_OVER = new float[TD_OVER];
			for (int i = 0; i < TD_OVER; ++i) {
				TD_SET_OVER[i] = i;
			}
			cl_float2* TO_OVER = oa.overlap_and_extend_for_STFT(TD_SET_OVER, TD_OVER, overlaped_full_frame, 10, powed_radix / 2, 0);
			int index = 0;
			for (int i = 0; i < fft_quotient; ++i) {
				for (int j = 0; j < 1024; ++j) {
					if (i * 512 + j >= TD_OVER) {
						goto TO_GOOD_BREAK;
					}
					Assert::IsTrue(TD_SET_OVER[i * 512 + j] == TO_OVER[index].x && TO_OVER[index].y == 0);
					++index;
				}
			}
		TO_GOOD_BREAK:
			delete[] TD_SET_OVER;
			delete[] TO_OVER;

		};
		TEST_METHOD(window_function_tester)
		{
			OPENCL_ACC oa = OPENCL_ACC("NVIDIA CUDA", "NVIDIA GeForce GTX 1660 Ti with Max-Q Design");

			cl_float2* hamming_test_data = new cl_float2[1024 * 10];
			for (int i = 0; i < 10240; ++i) {
				hamming_test_data[i].x = 1.0;
				hamming_test_data[i].y = 0;
			}
			oa.window_STFT(hamming_test_data, 10240, 10);
			for (int i = 0; i < 10; ++i) {
				for (int j = 0; j < 1024; ++j) {
					float hamming = 0.42f - 0.5f * cos(2.0f * CL_M_PI * (float)j / 1024.0f) + 0.08f * cos(4.0f * CL_M_PI * (float)j / 1024.0f);
					Assert::IsFalse(std::abs(hamming - hamming_test_data[i * 1024 + j].x) >= 0.1 || 0 != hamming_test_data[i * 1024 + j].y);
				}
			}
			delete[] hamming_test_data;
		};
		TEST_METHOD(bit_reverse_tester) {
			OPENCL_ACC oa = OPENCL_ACC("NVIDIA CUDA", "NVIDIA GeForce GTX 1660 Ti with Max-Q Design");
			cl_float2* bit_reverse_test_data = new cl_float2[10240];
			    for (int i = 0; i < 10; ++i) {
			        for (int j = 0; j < 1024; ++j) {
						bit_reverse_test_data[i * 1024 + j].x = j;
						bit_reverse_test_data[i * 1024 + j].y = 0;
			        }
			    }
			
			oa.bit_reverse_STFT(bit_reverse_test_data,10240,10);
			float origin[1024];
			for (int i = 0; i < 1024; ++i) {
			    origin[i] = reverseBits(i,10);
			}
			for (int i = 0; i < 10; ++i) {
			    for (int j = 0; j < 1024; ++j) {
					Assert::IsFalse(bit_reverse_test_data[i * 1024 + j].x != origin[j] || bit_reverse_test_data[i * 1024 + j].y != 0);
			    }
			}
			delete[] bit_reverse_test_data;
		};
			
		TEST_METHOD(power_data_tester) {
			OPENCL_ACC oa = OPENCL_ACC("NVIDIA CUDA", "NVIDIA GeForce GTX 1660 Ti with Max-Q Design");
			cl_float2* power_test_data = new cl_float2[1024 * 10];
			for (int i = 0; i < 10240; ++i) {
			    power_test_data[i].x = i%1024;
			    power_test_data[i].y = i%1024;
			}
			float* powered_data = oa.power_them(power_test_data, 10240, 10);
			for (int i = 0; i < 10240 / 2; ++i) {
				int j = i % 512;
				float sq = sqrtf(2.0f * powf(j, 2));
				Assert::IsFalse(std::abs(powered_data[i] - sq) >= 0.0001);
			}
			delete[] powered_data;
		};
			

		TEST_METHOD(DaC_tester) {
			OPENCL_ACC oa = OPENCL_ACC("NVIDIA CUDA", "NVIDIA GeForce GTX 1660 Ti with Max-Q Design");
			float* DaC_test_data = new float[1024];
			float* DaC_origin_data = new float[1024];
			for (int i = 0; i < 1024; ++i) {
				DaC_test_data[i] = i;
				DaC_origin_data[i] = i;
			}
			oa.gpgpu_facade(
				oa.CLS->DaC,
				DaC_test_data,
				1024,
				DaC_test_data,
				1024,
				512,
				1024
			);
			oa.gpgpu_facade(
				oa.CLS->DaC,
				DaC_test_data,
				1024,
				DaC_test_data,
				1024,
				256,
				512
			);
			for (int i = 0; i < 512; ++i) {
				DaC_origin_data[i] = DaC_origin_data[i * 2] + DaC_origin_data[i * 2 + 1];
			}
			for (int i = 0; i < 512; ++i) {
				DaC_origin_data[i] = DaC_origin_data[i * 2] + DaC_origin_data[i * 2 + 1];
			}
			for (int i = 0; i < 256; ++i) {
				Assert::AreEqual(DaC_origin_data[i], DaC_test_data[i]);
			}
			delete[] DaC_test_data;
			delete[] DaC_origin_data;
		};
			
		TEST_METHOD(three_band_split_tester) {
			OPENCL_ACC oa = OPENCL_ACC("NVIDIA CUDA", "NVIDIA GeForce GTX 1660 Ti with Max-Q Design");
			int powed_size = pow(2, 10 - 1);
			ma_uint64 only_usables = 2048000000;
			float* test_data = new float[only_usables];
			for (ma_uint64 i = 0; i < only_usables; ++i) {
				test_data[i] = i;
			}

			double freq_jump_size = ((double)DEFAULT_SAMPLERATE) / (double)(powed_size * 2);

			int low_mid = (int)(((double)EQ_LOW_MID) / freq_jump_size) + 1;
			int mid_high = (int)(((double)EQ_MID_HIGH) / freq_jump_size) + 1;
			float* lows = nullptr;
			float* mids = nullptr;
			float* highs = nullptr;
			oa.gpgpu_facade<float, float>(
				oa.CLS->split_low_band,
				test_data,
				only_usables,
				lows,
				2 * low_mid,
				2 * low_mid,
				10,
				low_mid
			);
			for (int i = 0; i < low_mid; ++i) {
				float compare = i < 2 ? 0 : i;
				Assert::AreEqual(lows[i], compare);
			}
			for (int i = 0; i < low_mid; ++i) {
				float compare = i < 2 ? 0 : i+1024;
				Assert::AreEqual(lows[low_mid+i], compare);
			}
		};
		
		TEST_METHOD(thread_tester) {
			OPENCL_ACC oa = OPENCL_ACC("NVIDIA CUDA", "NVIDIA GeForce GTX 1660 Ti with Max-Q Design");
			Kernel KN = cl_facade::create_kernel(oa.CLS->DaC, "entry_point", oa.CT, oa.DV);
			CommandQueue CQ = clboost::make_cq(oa.CT, oa.DV);
			ma_uint64 test_set_size = 1024;
			float* test_data = new float[test_set_size];
			for (ma_uint64 i = 0; i < test_set_size; ++i) {
				test_data[i] = i;
			}
			//oa.thread_worker(KN,CQ,test_data,)
		};
		//    float* random_float_data = TD_butterfly_tester();
			//    cl_float2* butterfly_data = new cl_float2[10240];
			//    for (int i = 0; i < 10240; ++i) {
			//        butterfly_data[i].x = random_float_data[i];
			//        butterfly_data[i].y = 0;
			//    }
			//
			//    bit_reverse_STFT(butterfly_data, 10240, 10);
			//
			//
			//    std::vector<std::complex<float>> DFT_out = DFT_STFT(random_float_data, 10240, 10);
			//    butterfly_STFT(butterfly_data, 10240, 10);
			//    TO_DFT_TESTER(butterfly_data, DFT_out, 10240);
		
	};



}
