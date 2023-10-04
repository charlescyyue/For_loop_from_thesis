/*generated in September 2023*/

#include <stdio.h>
#include <math.h>

#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int N ;
typedef  int K ;


# if !defined(DATASET_XS) && !defined(DATASET_S) && !defined(DATASET_M) && !defined(DATASET_L) && !defined(DATASET_XL) && !defined(DATASET_XXL) && !defined(DATASET_XXXL)
# define DATASET_M
# endif

#if !defined(M) && !defined(N)
# ifdef DATASET_XS
# define M 16
# define N 16
#endif

# ifdef DATASET_S
# define M 64
# define N 64
#endif

# ifdef DATASET_M
# define M 256
# define N 256
#endif

# ifdef DATASET_L
# define M 1024
# define N 1024
#endif

# ifdef DATASET_XL
# define M 4096
# define N 4096
#endif

# ifdef DATASET_XXL
# define M 16384
# define N 16384
#endif

# ifdef DATASET_XXXL
# define M 65536
# define N 65536
#endif

#endif


int main(){
int K;
int* A;
int* B;
int* C;
int b0;
int b1;
int** p_C;
int** s_A;
int** s_B;
int t0;
int t1;

#pragma scop
for ( int g1 = 16 * b0 ; g1 < M; g1 += 4096)
for ( int g3 = 16 * b1 ; g3 < N; g3 += 4096) {
if (K >= 1)
if (N >= t1 + g3 + 1 && M >= t0 + g1 + 1) {
p_C [0][0] = C [( t0 + g1 ) * (N) + t1 + g3 ];
if (M >= t0 + g1 + 9)
p_C [1][0] = C [( t0 + g1 + 8) * (N) + t1 + g3 ];
}
for ( int g9 = 0; g9 <= (K >= 1 ? K - 1 : 0); g9 += 16) {

if (K >= g9 + 1) {
if (N >= t1 + g3 + 1)
for ( int c0 = t0 ; c0 <= 42; c0 += 8)
s_B [ c0 ][ t1 ] = B [( g9 + c0 ) * (N) + t1 + g3 ];
if (K >= t1 + g9 + 1)
for ( int c0 = t0 ; c0 <= 42; c0 += 8)
s_A [ c0 ][ t1 ] = A [( g1 + c0 ) * (K) + t1 + g9 ];
}
if ( g9 == 0 && M >= t0 + g1 + 1 && N >= t1 + g3 + 1) {
p_C [0][0] = (0);
if (M >= t0 + g1 + 9)
p_C [1][0] = (0);
}
if (M >= t0 + g1 + 1 && N >= t1 + g3 + 1)
for ( int c2 = 0; c2 <= 42; c2 += 1) {
p_C [0][0] = ( p_C [0][0] + ( s_A [ t0 ][ c2 ] * s_B [ c2 ][ t1 ]));
if (M >= t0 + g1 + 9)
p_C [1][0] = ( p_C [1][0] + ( s_A [ t0 + 8][ c2 ] * s_B [ c2 ][ t1 ]));
}
}
if (N >= t1 + g3 + 1 && M >= t0 + g1 + 1) {
C [( t0 + g1 ) * (N) + t1 + g3 ] = p_C [0][0];
if (M >= t0 + g1 + 9)
C [( t0 + g1 + 8) * (N) + t1 + g3 ] = p_C [1][0];
}
}

#pragma endscop
printf("The value of A is %p", A);
printf("The value of B is %p", B);
printf("The value of C is %p", C);
printf("The value of p_C is %p", p_C);
printf("The value of s_A is %p", s_A);
printf("The value of s_B is %p", s_B);

return 0;
}