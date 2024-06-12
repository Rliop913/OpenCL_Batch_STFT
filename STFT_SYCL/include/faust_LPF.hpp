/* ------------------------------------------------------------
name: "untitled"
Code generated with Faust 2.60.3 (https://faust.grame.fr)
Compilation options: -lang cpp -ct 1 -es 1 -mcd 16 -single -ftz 0 -vec -lv 0 -vs 480
------------------------------------------------------------ */

#ifndef  __Faust_LPF_H__
#define  __Faust_LPF_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS Faust_LPF
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

static float Faust_LPF_faustpower2_f(float value) {
	return value * value;
}

class Faust_LPF{
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fRec5_perm[4];
	float fRec4_perm[4];
	float fRec3_perm[4];
	float fRec2_perm[4];
	float fRec1_perm[4];
	float fRec0_perm[4];
	
 public:
	 int low_freq_value = 500;
	Faust_LPF() {}


	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = 3.1415927f / std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
	}
	
	
	void instanceClear() {
		for (int l0 = 0; l0 < 4; l0 = l0 + 1) {
			fRec5_perm[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 4; l1 = l1 + 1) {
			fRec4_perm[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 4; l2 = l2 + 1) {
			fRec3_perm[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 4; l3 = l3 + 1) {
			fRec2_perm[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 4; l4 = l4 + 1) {
			fRec1_perm[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 4; l5 = l5 + 1) {
			fRec0_perm[l5] = 0.0f;
		}
	}
	
	void init(int sample_rate) {
		instanceInit(sample_rate);
	}
	void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceClear();
	}
	
	virtual Faust_LPF* clone() {
		return new Faust_LPF();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void compute(unsigned long long count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0_ptr = inputs[0];
		FAUSTFLOAT* output0_ptr = outputs[0];
		float fSlow0 = std::tan(fConst0 * float(low_freq_value));
		float fSlow1 = 2.0f * (1.0f - 1.0f / Faust_LPF_faustpower2_f(fSlow0));
		float fSlow2 = 1.0f / fSlow0;
		float fSlow3 = (fSlow2 + -1.9828898f) / fSlow0 + 1.0f;
		float fSlow4 = 1.0f / ((fSlow2 + 1.9828898f) / fSlow0 + 1.0f);
		float fRec5_tmp[484];
		float* fRec5 = &fRec5_tmp[4];
		float fSlow5 = (fSlow2 + -1.847759f) / fSlow0 + 1.0f;
		float fSlow6 = 1.0f / ((fSlow2 + 1.847759f) / fSlow0 + 1.0f);
		float fRec4_tmp[484];
		float* fRec4 = &fRec4_tmp[4];
		float fSlow7 = (fSlow2 + -1.5867066f) / fSlow0 + 1.0f;
		float fSlow8 = 1.0f / ((fSlow2 + 1.5867066f) / fSlow0 + 1.0f);
		float fRec3_tmp[484];
		float* fRec3 = &fRec3_tmp[4];
		float fSlow9 = (fSlow2 + -1.2175229f) / fSlow0 + 1.0f;
		float fSlow10 = 1.0f / ((fSlow2 + 1.2175229f) / fSlow0 + 1.0f);
		float fRec2_tmp[484];
		float* fRec2 = &fRec2_tmp[4];
		float fSlow11 = (fSlow2 + -0.76536685f) / fSlow0 + 1.0f;
		float fSlow12 = 1.0f / ((fSlow2 + 0.76536685f) / fSlow0 + 1.0f);
		float fRec1_tmp[484];
		float* fRec1 = &fRec1_tmp[4];
		float fSlow13 = (fSlow2 + -0.26105237f) / fSlow0 + 1.0f;
		float fSlow14 = 1.0f / ((fSlow2 + 0.26105237f) / fSlow0 + 1.0f);
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
				fRec5_tmp[j0] = fRec5_perm[j0];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec5[i] = float(input0[i]) - fSlow4 * (fSlow3 * fRec5[i - 2] + fSlow1 * fRec5[i - 1]);
			}
			/* Post code */
			for (int j1 = 0; j1 < 4; j1 = j1 + 1) {
				fRec5_perm[j1] = fRec5_tmp[vsize + j1];
			}
			/* Recursive loop 1 */
			/* Pre code */
			for (int j2 = 0; j2 < 4; j2 = j2 + 1) {
				fRec4_tmp[j2] = fRec4_perm[j2];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec4[i] = fSlow4 * (fRec5[i - 2] + fRec5[i] + 2.0f * fRec5[i - 1]) - fSlow6 * (fSlow5 * fRec4[i - 2] + fSlow1 * fRec4[i - 1]);
			}
			/* Post code */
			for (int j3 = 0; j3 < 4; j3 = j3 + 1) {
				fRec4_perm[j3] = fRec4_tmp[vsize + j3];
			}
			/* Recursive loop 2 */
			/* Pre code */
			for (int j4 = 0; j4 < 4; j4 = j4 + 1) {
				fRec3_tmp[j4] = fRec3_perm[j4];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec3[i] = fSlow6 * (fRec4[i - 2] + fRec4[i] + 2.0f * fRec4[i - 1]) - fSlow8 * (fSlow7 * fRec3[i - 2] + fSlow1 * fRec3[i - 1]);
			}
			/* Post code */
			for (int j5 = 0; j5 < 4; j5 = j5 + 1) {
				fRec3_perm[j5] = fRec3_tmp[vsize + j5];
			}
			/* Recursive loop 3 */
			/* Pre code */
			for (int j6 = 0; j6 < 4; j6 = j6 + 1) {
				fRec2_tmp[j6] = fRec2_perm[j6];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec2[i] = fSlow8 * (fRec3[i - 2] + fRec3[i] + 2.0f * fRec3[i - 1]) - fSlow10 * (fSlow9 * fRec2[i - 2] + fSlow1 * fRec2[i - 1]);
			}
			/* Post code */
			for (int j7 = 0; j7 < 4; j7 = j7 + 1) {
				fRec2_perm[j7] = fRec2_tmp[vsize + j7];
			}
			/* Recursive loop 4 */
			/* Pre code */
			for (int j8 = 0; j8 < 4; j8 = j8 + 1) {
				fRec1_tmp[j8] = fRec1_perm[j8];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec1[i] = fSlow10 * (fRec2[i - 2] + fRec2[i] + 2.0f * fRec2[i - 1]) - fSlow12 * (fSlow11 * fRec1[i - 2] + fSlow1 * fRec1[i - 1]);
			}
			/* Post code */
			for (int j9 = 0; j9 < 4; j9 = j9 + 1) {
				fRec1_perm[j9] = fRec1_tmp[vsize + j9];
			}
			/* Recursive loop 5 */
			/* Pre code */
			for (int j10 = 0; j10 < 4; j10 = j10 + 1) {
				fRec0_tmp[j10] = fRec0_perm[j10];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec0[i] = fSlow12 * (fRec1[i - 2] + fRec1[i] + 2.0f * fRec1[i - 1]) - fSlow14 * (fSlow13 * fRec0[i - 2] + fSlow1 * fRec0[i - 1]);
			}
			/* Post code */
			for (int j11 = 0; j11 < 4; j11 = j11 + 1) {
				fRec0_perm[j11] = fRec0_tmp[vsize + j11];
			}
			/* Vectorizable loop 6 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				output0[i] = FAUSTFLOAT(fSlow14 * (fRec0[i - 2] + fRec0[i] + 2.0f * fRec0[i - 1]));
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
				fRec5_tmp[j0] = fRec5_perm[j0];
			}
			/* Compute code */
			for (unsigned long long i = 0; i < vsize; i = i + 1) {
				fRec5[i] = float(input0[i]) - fSlow4 * (fSlow3 * fRec5[i - 2] + fSlow1 * fRec5[i - 1]);
			}
			/* Post code */
			for (int j1 = 0; j1 < 4; j1 = j1 + 1) {
				fRec5_perm[j1] = fRec5_tmp[vsize + j1];
			}
			/* Recursive loop 1 */
			/* Pre code */
			for (int j2 = 0; j2 < 4; j2 = j2 + 1) {
				fRec4_tmp[j2] = fRec4_perm[j2];
			}
			/* Compute code */
			for (unsigned long long i = 0; i < vsize; i = i + 1) {
				fRec4[i] = fSlow4 * (fRec5[i - 2] + fRec5[i] + 2.0f * fRec5[i - 1]) - fSlow6 * (fSlow5 * fRec4[i - 2] + fSlow1 * fRec4[i - 1]);
			}
			/* Post code */
			for (int j3 = 0; j3 < 4; j3 = j3 + 1) {
				fRec4_perm[j3] = fRec4_tmp[vsize + j3];
			}
			/* Recursive loop 2 */
			/* Pre code */
			for (int j4 = 0; j4 < 4; j4 = j4 + 1) {
				fRec3_tmp[j4] = fRec3_perm[j4];
			}
			/* Compute code */
			for (unsigned long long i = 0; i < vsize; i = i + 1) {
				fRec3[i] = fSlow6 * (fRec4[i - 2] + fRec4[i] + 2.0f * fRec4[i - 1]) - fSlow8 * (fSlow7 * fRec3[i - 2] + fSlow1 * fRec3[i - 1]);
			}
			/* Post code */
			for (int j5 = 0; j5 < 4; j5 = j5 + 1) {
				fRec3_perm[j5] = fRec3_tmp[vsize + j5];
			}
			/* Recursive loop 3 */
			/* Pre code */
			for (int j6 = 0; j6 < 4; j6 = j6 + 1) {
				fRec2_tmp[j6] = fRec2_perm[j6];
			}
			/* Compute code */
			for (unsigned long long i = 0; i < vsize; i = i + 1) {
				fRec2[i] = fSlow8 * (fRec3[i - 2] + fRec3[i] + 2.0f * fRec3[i - 1]) - fSlow10 * (fSlow9 * fRec2[i - 2] + fSlow1 * fRec2[i - 1]);
			}
			/* Post code */
			for (int j7 = 0; j7 < 4; j7 = j7 + 1) {
				fRec2_perm[j7] = fRec2_tmp[vsize + j7];
			}
			/* Recursive loop 4 */
			/* Pre code */
			for (int j8 = 0; j8 < 4; j8 = j8 + 1) {
				fRec1_tmp[j8] = fRec1_perm[j8];
			}
			/* Compute code */
			for (unsigned long long i = 0; i < vsize; i = i + 1) {
				fRec1[i] = fSlow10 * (fRec2[i - 2] + fRec2[i] + 2.0f * fRec2[i - 1]) - fSlow12 * (fSlow11 * fRec1[i - 2] + fSlow1 * fRec1[i - 1]);
			}
			/* Post code */
			for (int j9 = 0; j9 < 4; j9 = j9 + 1) {
				fRec1_perm[j9] = fRec1_tmp[vsize + j9];
			}
			/* Recursive loop 5 */
			/* Pre code */
			for (int j10 = 0; j10 < 4; j10 = j10 + 1) {
				fRec0_tmp[j10] = fRec0_perm[j10];
			}
			/* Compute code */
			for (unsigned long long i = 0; i < vsize; i = i + 1) {
				fRec0[i] = fSlow12 * (fRec1[i - 2] + fRec1[i] + 2.0f * fRec1[i - 1]) - fSlow14 * (fSlow13 * fRec0[i - 2] + fSlow1 * fRec0[i - 1]);
			}
			/* Post code */
			for (int j11 = 0; j11 < 4; j11 = j11 + 1) {
				fRec0_perm[j11] = fRec0_tmp[vsize + j11];
			}
			/* Vectorizable loop 6 */
			/* Compute code */
			for (unsigned long long i = 0; i < vsize; i = i + 1) {
				output0[i] = FAUSTFLOAT(fSlow14 * (fRec0[i - 2] + fRec0[i] + 2.0f * fRec0[i - 1]));
			}
		}
	}

};

#endif
