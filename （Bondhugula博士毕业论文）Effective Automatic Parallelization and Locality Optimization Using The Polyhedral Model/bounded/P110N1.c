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

#if !defined(N)
# ifdef DATASET_XS
# define N 16
#endif

# ifdef DATASET_S
# define N 64
#endif

# ifdef DATASET_M
# define N 256
#endif

# ifdef DATASET_L
# define N 1024
#endif

# ifdef DATASET_XL
# define N 4096
#endif

# ifdef DATASET_XXL
# define N 16384
#endif

# ifdef DATASET_XXXL
# define N 65536
#endif

#endif


int main(){
int c1;
int c2;
int c4;
int c5;
int c8;
int**** A;
scalar_t__**** B;
int** C1;
int** C2;
int** C3;
int** C4;
int**** T1;
int**** T2;
int**** T3;

#pragma scop
for (c1=0;c1<=N-1;c1++) {
for (c2=0;c2<=N-1;c2++) {
for (c4=0;c4<=N-1;c4++) {
for (c5=0;c5<=N-1;c5++) {
for (c8=0;c8<=N-1;c8++) {
{T1[c1][c5 ][ c4 ][ c2]=A[c8][c5 ][ c4 ][ c2]*C4[c8][c1]+T1[c1][c5 ][ c4 ][ c2 ];} ;
}
for (c8=0;c8<=N-1;c8++) {
{T2[c1][c8 ][ c4 ][ c2]=T1[c1][c5 ][ c4 ][ c2]*C3[c5][c8]+T2[c1][c8 ][ c4 ][ c2 ];} ;
}
}
}
for (c4=0;c4<=N-1;c4++) {
for (c5=0;c5<=N-1;c5++) {
for (c8=0;c8<=N-1;c8++) {
{T3[c1][c4 ][ c5 ][ c2]=T2[c1][c4 ][ c8 ][ c2]*C2[c8][c5]+T3[c1][c4 ][ c5 ][ c2 ];} ;
}
for (c8=0;c8<=N-1;c8++) {
{B[c1][c4 ][ c5 ][ c8]=T3[c1][c4 ][ c5 ][ c2]*C1[c2][c8]+B[c1][c4 ][ c5 ][ c8 ];} ;
}
}
}
}
}

#pragma endscop
printf("The value of A is %p", A);
printf("The value of B is %p", B);
printf("The value of C1 is %p", C1);
printf("The value of C2 is %p", C2);
printf("The value of C3 is %p", C3);
printf("The value of C4 is %p", C4);
printf("The value of T1 is %p", T1);
printf("The value of T2 is %p", T2);
printf("The value of T3 is %p", T3);

return 0;
}