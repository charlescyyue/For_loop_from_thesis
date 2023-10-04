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


# if !defined(DATASET_XS) && !defined(DATASET_S) && !defined(DATASET_M) && !defined(DATASET_L) && !defined(DATASET_XL) && !defined(DATASET_XXL) && !defined(DATASET_XXXL)
# define DATASET_M
# endif

#if !defined(M) && !defined(N) && !defined(K)
# ifdef DATASET_XS
# define M 16
# define N 16
# define K 16
#endif

# ifdef DATASET_S
# define M 64
# define N 64
# define K 64
#endif

# ifdef DATASET_M
# define M 256
# define N 256
# define K 256
#endif

# ifdef DATASET_L
# define M 1024
# define N 1024
# define K 1024
#endif

# ifdef DATASET_XL
# define M 4096
# define N 4096
# define K 4096
#endif

# ifdef DATASET_XXL
# define M 16384
# define N 16384
# define K 16384
#endif

# ifdef DATASET_XXXL
# define M 65536
# define N 65536
# define K 65536
#endif

#endif


int main(){
int* A;
int* B;
scalar_t__* C;
int b0;
int b1;
scalar_t__** private_C;
int** shared_A;
int** shared_B;
int t0;
int t1;

#pragma scop
for ( int c0 = 32 * b0; c0 < M; c0 += 8192)
for ( int c1 = 32 * b1; c1 < N; c1 += 8192) {
for ( int c2 = 0; c2 < K; c2 += 32) {
if (M >= t0 + c0 + 1)
for ( int c4 = t1; c4 <= 42; c4 += 16)
shared_A [t0 ][ c4] = A[( t0 + c0) * K + (c2 + c4 )];
if (K >= t0 + c2 + 1)
for ( int c4 = t1; c4 <= 42; c4 += 16)
shared_B [t0 ][ c4] = B[( t0 + c2) * N + (c1 + c4 )];
if (M >= t0 + c0 + 1 && N >= t1 + c1 + 1 && c2 == 0) {
private_C [0][0] = 0;
if (N >= t1 + c1 + 17)
private_C [0][1] = 0;
}
if (M >= t0 + c0 + 1 && N >= t1 + c1 + 1)
for ( int c3 = 0; c3 <= 42; c3 += 1) {
private_C [0][0] = ( private_C [0][0] + ( shared_A [t0 ][ c3] * shared_B [c3 ][ t1 ]));
if (N >= t1 + c1 + 17)
private_C [0][1] = ( private_C [0][1] + ( shared_A [t0 ][ c3] * shared_B [c3 ][ t1 + 16]));
}
}
if (M >= t0 + c0 + 1 && N >= t1 + c1 + 1) {
C[( t0 + c0) * N + (t1 + c1 )] = private_C [0][0];
if (N >= t1 + c1 + 17)
C[( t0 + c0) * N + (t1 + c1 + 16)] = private_C [0][1];
}
}

#pragma endscop
printf("The value of A is %p", A);
printf("The value of B is %p", B);
printf("The value of C is %p", C);
printf("The value of private_C is %p", private_C);
printf("The value of shared_A is %p", shared_A);
printf("The value of shared_B is %p", shared_B);

return 0;
}