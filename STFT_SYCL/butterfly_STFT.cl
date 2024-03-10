
//2 component vector to hold the real and imaginary parts of a complex number:
typedef float2 cfloat;

#define I ((cfloat)(0.0, 1.0))


/*
 * Return Real (Imaginary) component of complex number:
 */
inline float  real(cfloat a){
     return a.x;
}
inline float  imag(cfloat a){
     return a.y;
}

/*
 * Get the modulus of a complex number (its length):
 */
inline float cmod(cfloat a){
    return (sqrt(a.x*a.x + a.y*a.y));
}

/*
 * Get the argument of a complex number (its angle):
 * http://en.wikipedia.org/wiki/Complex_number#Absolute_value_and_argument
 */
inline float carg(cfloat a){
    if(a.x > 0){
        return atan(a.y / a.x);

    }else if(a.x < 0 && a.y >= 0){
        return atan(a.y / a.x) + M_PI;

    }else if(a.x < 0 && a.y < 0){
        return atan(a.y / a.x) - M_PI;

    }else if(a.x == 0 && a.y > 0){
        return M_PI/2;

    }else if(a.x == 0 && a.y < 0){
        return -M_PI/2;

    }else{
        return 0;
    }
}

/*
 * Multiply two complex numbers:
 *
 *  a = (aReal + I*aImag)
 *  b = (bReal + I*bImag)
 *  a * b = (aReal + I*aImag) * (bReal + I*bImag)
 *        = aReal*bReal +I*aReal*bImag +I*aImag*bReal +I^2*aImag*bImag
 *        = (aReal*bReal - aImag*bImag) + I*(aReal*bImag + aImag*bReal)
 */
inline cfloat  cmult(cfloat a, cfloat b){
    return (cfloat)( a.x*b.x - a.y*b.y, a.x*b.y + a.y*b.x);
}


/*
 * Divide two complex numbers:
 *
 *  aReal + I*aImag     (aReal + I*aImag) * (bReal - I*bImag)
 * ----------------- = ---------------------------------------
 *  bReal + I*bImag     (bReal + I*bImag) * (bReal - I*bImag)
 * 
 *        aReal*bReal - I*aReal*bImag + I*aImag*bReal - I^2*aImag*bImag
 *     = ---------------------------------------------------------------
 *            bReal^2 - I*bReal*bImag + I*bImag*bReal  -I^2*bImag^2
 * 
 *        aReal*bReal + aImag*bImag         aImag*bReal - Real*bImag 
 *     = ---------------------------- + I* --------------------------
 *            bReal^2 + bImag^2                bReal^2 + bImag^2
 * 
 */
inline cfloat cdiv(cfloat a, cfloat b){
    return (cfloat)((a.x*b.x + a.y*b.y)/(b.x*b.x + b.y*b.y), (a.y*b.x - a.x*b.y)/(b.x*b.x + b.y*b.y));
}


cfloat twiddle(int high, int low)
{
    cfloat temp;
    float angle = 2.0*((float)high/(float)low);
    temp.x = cospi(angle);
    temp.y = -1.0*sinpi(angle);
    return temp;
}

long2 indexer(const long ID,const int stage)
{
    long2 temp;
    long powed = pow(2.0, stage);
    temp.x = (ID%(powed))+powed*2*(ID/powed);
    temp.y = temp.x+powed;
    return temp;
}


__kernel void butterfly_stft(__global float2* in_frame, __global float2* out_frame, int radix_2, int stage)
{
    long powed_stage = (long)pow(2.0,stage);
    long myid = get_global_id(0);
    long2 origin_pair=indexer(myid,stage);
    cfloat this_twiddle = twiddle(myid%powed_stage,powed_stage*2);
    this_twiddle = cmult(in_frame[origin_pair.y],this_twiddle);
    out_frame[origin_pair.x]=in_frame[origin_pair.x]+this_twiddle;
    out_frame[origin_pair.y]=in_frame[origin_pair.x]-this_twiddle;
    
}




