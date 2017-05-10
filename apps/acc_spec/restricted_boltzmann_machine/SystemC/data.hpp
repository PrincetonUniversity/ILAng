#ifndef __DATA_H__
#define __DATA_H__

//randum
#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */
#define FRACTION 1.0/4294967296.0
#define mag0 0x0UL
#define mag1 0x9908b0dfUL
//parameter
#define DEBUG 0
#define K 5						       //movie rating range
#define LEARN_RATE 0.5

///accelerator configuration
#define NUM_MOVIE_MAX   100               //number of movies stored in the PLM
#define NUM_HIDDEN_MAX  100
#define NUM_VISIBLE_MAX (K*NUM_MOVIE_MAX) //visible units, k cells represent a movie -- u16

///data types
#define u8 unsigned char
#define u16 unsigned short
#define u32 unsigned int
#define u64 long long 
#define int32 int
#define s16 short

#ifndef DATA_FX_HPP
#define DATA_FX_HPP

//#define CPP_FP
#define SC_FIXED_POINT
//#define CTOS_SC_FIXED_POINT

#ifdef CPP_FP
#define DATA01_D float
#define DATA05_D float
#define DATA_sum float
#define DATA_sum_ float
#define DATA_edge float //0 +/- LOOPS*LEARN Rate 0.1*640=64 
#define fconst float

#elif defined(SC_FIXED_POINT)
#define DATA01_D ctos_sc_dt::sc_ufixed<64,1>
#define DATA05_D ctos_sc_dt::sc_ufixed<32,3>
#define DATA_sum3 ctos_sc_dt::sc_ufixed<64,64>
#define DATA_pow ctos_sc_dt::sc_ufixed<32,32>
#define DATA_sum_ ctos_sc_dt::sc_fixed<16,15>
#define DATA_edge ctos_sc_dt::sc_fixed<8,7>
#define fconst ctos_sc_dt::sc_fixed<16,4>


#elif defined(CTOS_SC_FIXED_POINT)
#define DATA01_D ctos_sc_dt::sc_ufixed<64,1>
#define DATA05_D ctos_sc_dt::sc_ufixed<32,3>
#define DATA_sum3 ctos_sc_dt::sc_ufixed<64,64>
#define DATA_pow ctos_sc_dt::sc_ufixed<32,32>
#define DATA_sum_ ctos_sc_dt::sc_fixed<16,15>
#define DATA_edge ctos_sc_dt::sc_fixed<8,7>
#define fconst ctos_sc_dt::sc_fixed<16,4>

#endif /*CPP_FP*/
#endif /*DATA_FX_HPP*/


#endif /* __DATA_H__ */
