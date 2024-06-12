/* ------------------------------------------------------------
name: "untitled"
Code generated with Faust 2.60.3 (https://faust.grame.fr)
Compilation options: -lang cpp -ct 1 -es 1 -mcd 16 -single -ftz 0 -vec -lv 0 -vs 480
------------------------------------------------------------ */

#ifndef  __Faust_LHPF_H__
#define  __Faust_LHPF_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS Faust_LHPF
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

static float Faust_LHPF_faustpower2_f(float value) {
	return value * value;
}

class Faust_LHPF{
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fRec11_perm[4];
	float fRec10_perm[4];
	float fRec9_perm[4];
	float fRec8_perm[4];
	float fRec7_perm[4];
	float fRec6_perm[4];
	float fRec5_perm[4];
	float fRec4_perm[4];
	float fRec3_perm[4];
	float fRec2_perm[4];
	float fRec1_perm[4];
	float fRec0_perm[4];
	
 public:
	 int low_freq_value = 500;
	 int high_freq_value = 2000;
	Faust_LHPF() {}


	int getNumInputs() {
		return 1;
	}
	int getNumOutputs() {
		return 1;
	}
	
	
	void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = 3.1415927f / std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
	}
	
	
	void instanceClear() {
		for (int l0 = 0; l0 < 4; l0 = l0 + 1) {
			fRec11_perm[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 4; l1 = l1 + 1) {
			fRec10_perm[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 4; l2 = l2 + 1) {
			fRec9_perm[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 4; l3 = l3 + 1) {
			fRec8_perm[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 4; l4 = l4 + 1) {
			fRec7_perm[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 4; l5 = l5 + 1) {
			fRec6_perm[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 4; l6 = l6 + 1) {
			fRec5_perm[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 4; l7 = l7 + 1) {
			fRec4_perm[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 4; l8 = l8 + 1) {
			fRec3_perm[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 4; l9 = l9 + 1) {
			fRec2_perm[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 4; l10 = l10 + 1) {
			fRec1_perm[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 4; l11 = l11 + 1) {
			fRec0_perm[l11] = 0.0f;
		}
	}
	
	void init(int sample_rate) {
		instanceInit(sample_rate);
	}
	void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceClear();
	}
	
	Faust_LHPF* clone() {
		return new Faust_LHPF();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	
	void compute(unsigned long long count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0_ptr = inputs[0];
		FAUSTFLOAT* output0_ptr = outputs[0];
		float fSlow0 = std::tan(fConst0 * float(low_freq_value));
		float fSlow1 = 2.0f * (1.0f - 1.0f / Faust_LHPF_faustpower2_f(fSlow0));
		float fSlow2 = 1.0f / fSlow0;
		float fSlow3 = (fSlow2 + -1.9828898f) / fSlow0 + 1.0f;
		float fSlow4 = 1.0f / ((fSlow2 + 1.9828898f) / fSlow0 + 1.0f);
		float fRec11_tmp[484];
		float* fRec11 = &fRec11_tmp[4];
		float fSlow5 = (fSlow2 + -1.847759f) / fSlow0 + 1.0f;
		float fSlow6 = 1.0f / ((fSlow2 + 1.847759f) / fSlow0 + 1.0f);
		float fRec10_tmp[484];
		float* fRec10 = &fRec10_tmp[4];
		float fSlow7 = (fSlow2 + -1.5867066f) / fSlow0 + 1.0f;
		float fSlow8 = 1.0f / ((fSlow2 + 1.5867066f) / fSlow0 + 1.0f);
		float fRec9_tmp[484];
		float* fRec9 = &fRec9_tmp[4];
		float fSlow9 = (fSlow2 + -1.2175229f) / fSlow0 + 1.0f;
		float fSlow10 = 1.0f / ((fSlow2 + 1.2175229f) / fSlow0 + 1.0f);
		float fRec8_tmp[484];
		float* fRec8 = &fRec8_tmp[4];
		float fSlow11 = (fSlow2 + -0.76536685f) / fSlow0 + 1.0f;
		float fSlow12 = 1.0f / ((fSlow2 + 0.76536685f) / fSlow0 + 1.0f);
		float fRec7_tmp[484];
		float* fRec7 = &fRec7_tmp[4];
		float fSlow13 = (fSlow2 + -0.26105237f) / fSlow0 + 1.0f;
		float fSlow14 = 1.0f / ((fSlow2 + 0.26105237f) / fSlow0 + 1.0f);
		float fRec6_tmp[484];
		float* fRec6 = &fRec6_tmp[4];
		float fSlow15 = std::tan(fConst0 * float(high_freq_value));
		float fSlow16 = Faust_LHPF_faustpower2_f(fSlow15);
		float fSlow17 = 1.0f / fSlow16;
		float fSlow18 = 2.0f * (1.0f - fSlow17);
		float fSlow19 = 1.0f / fSlow15;
		float fSlow20 = (fSlow19 + -1.9828898f) / fSlow15 + 1.0f;
		float fSlow21 = 1.0f / ((fSlow19 + 1.9828898f) / fSlow15 + 1.0f);
		float fRec5_tmp[484];
		float* fRec5 = &fRec5_tmp[4];
		float fSlow22 = (fSlow19 + -1.847759f) / fSlow15 + 1.0f;
		float fSlow23 = 1.0f / ((fSlow19 + 1.847759f) / fSlow15 + 1.0f);
		float fSlow24 = 0.0f - 2.0f / fSlow16;
		float fRec4_tmp[484];
		float* fRec4 = &fRec4_tmp[4];
		float fSlow25 = (fSlow19 + -1.5867066f) / fSlow15 + 1.0f;
		float fSlow26 = 1.0f / ((fSlow19 + 1.5867066f) / fSlow15 + 1.0f);
		float fRec3_tmp[484];
		float* fRec3 = &fRec3_tmp[4];
		float fSlow27 = (fSlow19 + -1.2175229f) / fSlow15 + 1.0f;
		float fSlow28 = 1.0f / ((fSlow19 + 1.2175229f) / fSlow15 + 1.0f);
		float fRec2_tmp[484];
		float* fRec2 = &fRec2_tmp[4];
		float fSlow29 = (fSlow19 + -0.76536685f) / fSlow15 + 1.0f;
		float fSlow30 = 1.0f / ((fSlow19 + 0.76536685f) / fSlow15 + 1.0f);
		float fRec1_tmp[484];
		float* fRec1 = &fRec1_tmp[4];
		float fSlow31 = (fSlow19 + -0.26105237f) / fSlow15 + 1.0f;
		float fSlow32 = 1.0f / ((fSlow19 + 0.26105237f) / fSlow15 + 1.0f);
		float fRec0_tmp[484];
		float* fRec0 = &fRec0_tmp[4];
		unsigned long long vindex = 0;
		/* Main loop */
		for (vindex = 0; vindex <= (count - 480); vindex = vindex + 480) {
			FAUSTFLOAT* input0 = &input0_ptr[vindex];
			FAUSTFLOAT* output0 = &output0_ptr[vindex];
			int vsize = 480;
			/* Recursive loop 0 */
			/* Pre code */
			for (int j0 = 0; j0 < 4; j0 = j0 + 1) {
				fRec11_tmp[j0] = fRec11_perm[j0];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec11[i] = float(input0[i]) - fSlow4 * (fSlow3 * fRec11[i - 2] + fSlow1 * fRec11[i - 1]);
			}
			/* Post code */
			for (int j1 = 0; j1 < 4; j1 = j1 + 1) {
				fRec11_perm[j1] = fRec11_tmp[vsize + j1];
			}
			/* Recursive loop 1 */
			/* Pre code */
			for (int j2 = 0; j2 < 4; j2 = j2 + 1) {
				fRec10_tmp[j2] = fRec10_perm[j2];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec10[i] = fSlow4 * (fRec11[i - 2] + fRec11[i] + 2.0f * fRec11[i - 1]) - fSlow6 * (fSlow5 * fRec10[i - 2] + fSlow1 * fRec10[i - 1]);
			}
			/* Post code */
			for (int j3 = 0; j3 < 4; j3 = j3 + 1) {
				fRec10_perm[j3] = fRec10_tmp[vsize + j3];
			}
			/* Recursive loop 2 */
			/* Pre code */
			for (int j4 = 0; j4 < 4; j4 = j4 + 1) {
				fRec9_tmp[j4] = fRec9_perm[j4];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec9[i] = fSlow6 * (fRec10[i - 2] + fRec10[i] + 2.0f * fRec10[i - 1]) - fSlow8 * (fSlow7 * fRec9[i - 2] + fSlow1 * fRec9[i - 1]);
			}
			/* Post code */
			for (int j5 = 0; j5 < 4; j5 = j5 + 1) {
				fRec9_perm[j5] = fRec9_tmp[vsize + j5];
			}
			/* Recursive loop 3 */
			/* Pre code */
			for (int j6 = 0; j6 < 4; j6 = j6 + 1) {
				fRec8_tmp[j6] = fRec8_perm[j6];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec8[i] = fSlow8 * (fRec9[i - 2] + fRec9[i] + 2.0f * fRec9[i - 1]) - fSlow10 * (fSlow9 * fRec8[i - 2] + fSlow1 * fRec8[i - 1]);
			}
			/* Post code */
			for (int j7 = 0; j7 < 4; j7 = j7 + 1) {
				fRec8_perm[j7] = fRec8_tmp[vsize + j7];
			}
			/* Recursive loop 4 */
			/* Pre code */
			for (int j8 = 0; j8 < 4; j8 = j8 + 1) {
				fRec7_tmp[j8] = fRec7_perm[j8];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec7[i] = fSlow10 * (fRec8[i - 2] + fRec8[i] + 2.0f * fRec8[i - 1]) - fSlow12 * (fSlow11 * fRec7[i - 2] + fSlow1 * fRec7[i - 1]);
			}
			/* Post code */
			for (int j9 = 0; j9 < 4; j9 = j9 + 1) {
				fRec7_perm[j9] = fRec7_tmp[vsize + j9];
			}
			/* Recursive loop 5 */
			/* Pre code */
			for (int j10 = 0; j10 < 4; j10 = j10 + 1) {
				fRec6_tmp[j10] = fRec6_perm[j10];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec6[i] = fSlow12 * (fRec7[i - 2] + fRec7[i] + 2.0f * fRec7[i - 1]) - fSlow14 * (fSlow13 * fRec6[i - 2] + fSlow1 * fRec6[i - 1]);
			}
			/* Post code */
			for (int j11 = 0; j11 < 4; j11 = j11 + 1) {
				fRec6_perm[j11] = fRec6_tmp[vsize + j11];
			}
			/* Recursive loop 6 */
			/* Pre code */
			for (int j12 = 0; j12 < 4; j12 = j12 + 1) {
				fRec5_tmp[j12] = fRec5_perm[j12];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec5[i] = fSlow14 * (fRec6[i - 2] + fRec6[i] + 2.0f * fRec6[i - 1]) - fSlow21 * (fSlow20 * fRec5[i - 2] + fSlow18 * fRec5[i - 1]);
			}
			/* Post code */
			for (int j13 = 0; j13 < 4; j13 = j13 + 1) {
				fRec5_perm[j13] = fRec5_tmp[vsize + j13];
			}
			/* Recursive loop 7 */
			/* Pre code */
			for (int j14 = 0; j14 < 4; j14 = j14 + 1) {
				fRec4_tmp[j14] = fRec4_perm[j14];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec4[i] = fSlow21 * (fSlow17 * fRec5[i] + fSlow24 * fRec5[i - 1] + fSlow17 * fRec5[i - 2]) - fSlow23 * (fSlow22 * fRec4[i - 2] + fSlow18 * fRec4[i - 1]);
			}
			/* Post code */
			for (int j15 = 0; j15 < 4; j15 = j15 + 1) {
				fRec4_perm[j15] = fRec4_tmp[vsize + j15];
			}
			/* Recursive loop 8 */
			/* Pre code */
			for (int j16 = 0; j16 < 4; j16 = j16 + 1) {
				fRec3_tmp[j16] = fRec3_perm[j16];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec3[i] = fSlow23 * (fSlow24 * fRec4[i - 1] + fSlow17 * fRec4[i] + fSlow17 * fRec4[i - 2]) - fSlow26 * (fSlow25 * fRec3[i - 2] + fSlow18 * fRec3[i - 1]);
			}
			/* Post code */
			for (int j17 = 0; j17 < 4; j17 = j17 + 1) {
				fRec3_perm[j17] = fRec3_tmp[vsize + j17];
			}
			/* Recursive loop 9 */
			/* Pre code */
			for (int j18 = 0; j18 < 4; j18 = j18 + 1) {
				fRec2_tmp[j18] = fRec2_perm[j18];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec2[i] = fSlow26 * (fSlow24 * fRec3[i - 1] + fSlow17 * fRec3[i] + fSlow17 * fRec3[i - 2]) - fSlow28 * (fSlow27 * fRec2[i - 2] + fSlow18 * fRec2[i - 1]);
			}
			/* Post code */
			for (int j19 = 0; j19 < 4; j19 = j19 + 1) {
				fRec2_perm[j19] = fRec2_tmp[vsize + j19];
			}
			/* Recursive loop 10 */
			/* Pre code */
			for (int j20 = 0; j20 < 4; j20 = j20 + 1) {
				fRec1_tmp[j20] = fRec1_perm[j20];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec1[i] = fSlow28 * (fSlow17 * fRec2[i] + fSlow24 * fRec2[i - 1] + fSlow17 * fRec2[i - 2]) - fSlow30 * (fSlow29 * fRec1[i - 2] + fSlow18 * fRec1[i - 1]);
			}
			/* Post code */
			for (int j21 = 0; j21 < 4; j21 = j21 + 1) {
				fRec1_perm[j21] = fRec1_tmp[vsize + j21];
			}
			/* Recursive loop 11 */
			/* Pre code */
			for (int j22 = 0; j22 < 4; j22 = j22 + 1) {
				fRec0_tmp[j22] = fRec0_perm[j22];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec0[i] = fSlow30 * (fSlow17 * fRec1[i] + fSlow24 * fRec1[i - 1] + fSlow17 * fRec1[i - 2]) - fSlow32 * (fSlow31 * fRec0[i - 2] + fSlow18 * fRec0[i - 1]);
			}
			/* Post code */
			for (int j23 = 0; j23 < 4; j23 = j23 + 1) {
				fRec0_perm[j23] = fRec0_tmp[vsize + j23];
			}
			/* Vectorizable loop 12 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				output0[i] = FAUSTFLOAT(fSlow32 * (fSlow17 * fRec0[i] + fSlow24 * fRec0[i - 1] + fSlow17 * fRec0[i - 2]));
			}
		}
		/* Remaining frames */
		if (vindex < count) {
			FAUSTFLOAT* input0 = &input0_ptr[vindex];
			FAUSTFLOAT* output0 = &output0_ptr[vindex];
			unsigned long long vsize = count - vindex;
			/* Recursive loop 0 */
			/* Pre code */
			for (int j0 = 0; j0 < 4; j0 = j0 + 1) {
				fRec11_tmp[j0] = fRec11_perm[j0];
			}
			/* Compute code */
			for (unsigned long long i = 0; i < vsize; i = i + 1) {
				fRec11[i] = float(input0[i]) - fSlow4 * (fSlow3 * fRec11[i - 2] + fSlow1 * fRec11[i - 1]);
			}
			/* Post code */
			for (int j1 = 0; j1 < 4; j1 = j1 + 1) {
				fRec11_perm[j1] = fRec11_tmp[vsize + j1];
			}
			/* Recursive loop 1 */
			/* Pre code */
			for (int j2 = 0; j2 < 4; j2 = j2 + 1) {
				fRec10_tmp[j2] = fRec10_perm[j2];
			}
			/* Compute code */
			for (unsigned long long i = 0; i < vsize; i = i + 1) {
				fRec10[i] = fSlow4 * (fRec11[i - 2] + fRec11[i] + 2.0f * fRec11[i - 1]) - fSlow6 * (fSlow5 * fRec10[i - 2] + fSlow1 * fRec10[i - 1]);
			}
			/* Post code */
			for (int j3 = 0; j3 < 4; j3 = j3 + 1) {
				fRec10_perm[j3] = fRec10_tmp[vsize + j3];
			}
			/* Recursive loop 2 */
			/* Pre code */
			for (int j4 = 0; j4 < 4; j4 = j4 + 1) {
				fRec9_tmp[j4] = fRec9_perm[j4];
			}
			/* Compute code */
			for (unsigned long long i = 0; i < vsize; i = i + 1) {
				fRec9[i] = fSlow6 * (fRec10[i - 2] + fRec10[i] + 2.0f * fRec10[i - 1]) - fSlow8 * (fSlow7 * fRec9[i - 2] + fSlow1 * fRec9[i - 1]);
			}
			/* Post code */
			for (int j5 = 0; j5 < 4; j5 = j5 + 1) {
				fRec9_perm[j5] = fRec9_tmp[vsize + j5];
			}
			/* Recursive loop 3 */
			/* Pre code */
			for (int j6 = 0; j6 < 4; j6 = j6 + 1) {
				fRec8_tmp[j6] = fRec8_perm[j6];
			}
			/* Compute code */
			for (unsigned long long i = 0; i < vsize; i = i + 1) {
				fRec8[i] = fSlow8 * (fRec9[i - 2] + fRec9[i] + 2.0f * fRec9[i - 1]) - fSlow10 * (fSlow9 * fRec8[i - 2] + fSlow1 * fRec8[i - 1]);
			}
			/* Post code */
			for (int j7 = 0; j7 < 4; j7 = j7 + 1) {
				fRec8_perm[j7] = fRec8_tmp[vsize + j7];
			}
			/* Recursive loop 4 */
			/* Pre code */
			for (int j8 = 0; j8 < 4; j8 = j8 + 1) {
				fRec7_tmp[j8] = fRec7_perm[j8];
			}
			/* Compute code */
			for (unsigned long long i = 0; i < vsize; i = i + 1) {
				fRec7[i] = fSlow10 * (fRec8[i - 2] + fRec8[i] + 2.0f * fRec8[i - 1]) - fSlow12 * (fSlow11 * fRec7[i - 2] + fSlow1 * fRec7[i - 1]);
			}
			/* Post code */
			for (int j9 = 0; j9 < 4; j9 = j9 + 1) {
				fRec7_perm[j9] = fRec7_tmp[vsize + j9];
			}
			/* Recursive loop 5 */
			/* Pre code */
			for (int j10 = 0; j10 < 4; j10 = j10 + 1) {
				fRec6_tmp[j10] = fRec6_perm[j10];
			}
			/* Compute code */
			for (unsigned long long i = 0; i < vsize; i = i + 1) {
				fRec6[i] = fSlow12 * (fRec7[i - 2] + fRec7[i] + 2.0f * fRec7[i - 1]) - fSlow14 * (fSlow13 * fRec6[i - 2] + fSlow1 * fRec6[i - 1]);
			}
			/* Post code */
			for (int j11 = 0; j11 < 4; j11 = j11 + 1) {
				fRec6_perm[j11] = fRec6_tmp[vsize + j11];
			}
			/* Recursive loop 6 */
			/* Pre code */
			for (int j12 = 0; j12 < 4; j12 = j12 + 1) {
				fRec5_tmp[j12] = fRec5_perm[j12];
			}
			/* Compute code */
			for (unsigned long long i = 0; i < vsize; i = i + 1) {
				fRec5[i] = fSlow14 * (fRec6[i - 2] + fRec6[i] + 2.0f * fRec6[i - 1]) - fSlow21 * (fSlow20 * fRec5[i - 2] + fSlow18 * fRec5[i - 1]);
			}
			/* Post code */
			for (int j13 = 0; j13 < 4; j13 = j13 + 1) {
				fRec5_perm[j13] = fRec5_tmp[vsize + j13];
			}
			/* Recursive loop 7 */
			/* Pre code */
			for (int j14 = 0; j14 < 4; j14 = j14 + 1) {
				fRec4_tmp[j14] = fRec4_perm[j14];
			}
			/* Compute code */
			for (unsigned long long i = 0; i < vsize; i = i + 1) {
				fRec4[i] = fSlow21 * (fSlow17 * fRec5[i] + fSlow24 * fRec5[i - 1] + fSlow17 * fRec5[i - 2]) - fSlow23 * (fSlow22 * fRec4[i - 2] + fSlow18 * fRec4[i - 1]);
			}
			/* Post code */
			for (int j15 = 0; j15 < 4; j15 = j15 + 1) {
				fRec4_perm[j15] = fRec4_tmp[vsize + j15];
			}
			/* Recursive loop 8 */
			/* Pre code */
			for (int j16 = 0; j16 < 4; j16 = j16 + 1) {
				fRec3_tmp[j16] = fRec3_perm[j16];
			}
			/* Compute code */
			for (unsigned long long i = 0; i < vsize; i = i + 1) {
				fRec3[i] = fSlow23 * (fSlow24 * fRec4[i - 1] + fSlow17 * fRec4[i] + fSlow17 * fRec4[i - 2]) - fSlow26 * (fSlow25 * fRec3[i - 2] + fSlow18 * fRec3[i - 1]);
			}
			/* Post code */
			for (int j17 = 0; j17 < 4; j17 = j17 + 1) {
				fRec3_perm[j17] = fRec3_tmp[vsize + j17];
			}
			/* Recursive loop 9 */
			/* Pre code */
			for (int j18 = 0; j18 < 4; j18 = j18 + 1) {
				fRec2_tmp[j18] = fRec2_perm[j18];
			}
			/* Compute code */
			for (unsigned long long i = 0; i < vsize; i = i + 1) {
				fRec2[i] = fSlow26 * (fSlow24 * fRec3[i - 1] + fSlow17 * fRec3[i] + fSlow17 * fRec3[i - 2]) - fSlow28 * (fSlow27 * fRec2[i - 2] + fSlow18 * fRec2[i - 1]);
			}
			/* Post code */
			for (int j19 = 0; j19 < 4; j19 = j19 + 1) {
				fRec2_perm[j19] = fRec2_tmp[vsize + j19];
			}
			/* Recursive loop 10 */
			/* Pre code */
			for (int j20 = 0; j20 < 4; j20 = j20 + 1) {
				fRec1_tmp[j20] = fRec1_perm[j20];
			}
			/* Compute code */
			for (unsigned long long i = 0; i < vsize; i = i + 1) {
				fRec1[i] = fSlow28 * (fSlow17 * fRec2[i] + fSlow24 * fRec2[i - 1] + fSlow17 * fRec2[i - 2]) - fSlow30 * (fSlow29 * fRec1[i - 2] + fSlow18 * fRec1[i - 1]);
			}
			/* Post code */
			for (int j21 = 0; j21 < 4; j21 = j21 + 1) {
				fRec1_perm[j21] = fRec1_tmp[vsize + j21];
			}
			/* Recursive loop 11 */
			/* Pre code */
			for (int j22 = 0; j22 < 4; j22 = j22 + 1) {
				fRec0_tmp[j22] = fRec0_perm[j22];
			}
			/* Compute code */
			for (unsigned long long i = 0; i < vsize; i = i + 1) {
				fRec0[i] = fSlow30 * (fSlow17 * fRec1[i] + fSlow24 * fRec1[i - 1] + fSlow17 * fRec1[i - 2]) - fSlow32 * (fSlow31 * fRec0[i - 2] + fSlow18 * fRec0[i - 1]);
			}
			/* Post code */
			for (int j23 = 0; j23 < 4; j23 = j23 + 1) {
				fRec0_perm[j23] = fRec0_tmp[vsize + j23];
			}
			/* Vectorizable loop 12 */
			/* Compute code */
			for (unsigned long long i = 0; i < vsize; i = i + 1) {
				output0[i] = FAUSTFLOAT(fSlow32 * (fSlow17 * fRec0[i] + fSlow24 * fRec0[i - 1] + fSlow17 * fRec0[i - 2]));
			}
		}
	}

};

#endif
