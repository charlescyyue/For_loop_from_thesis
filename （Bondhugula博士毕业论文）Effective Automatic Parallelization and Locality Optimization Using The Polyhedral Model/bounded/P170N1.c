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

#if !defined(ub1)
# ifdef DATASET_XS
# define ub1 16
#endif

# ifdef DATASET_S
# define ub1 64
#endif

# ifdef DATASET_M
# define ub1 256
#endif

# ifdef DATASET_L
# define ub1 1024
#endif

# ifdef DATASET_XL
# define ub1 4096
#endif

# ifdef DATASET_XXL
# define ub1 16384
#endif

# ifdef DATASET_XXXL
# define ub1 65536
#endif

#endif


int main(){
int t0;
int t1;
int t3;
size_t t5;
size_t t6;
size_t t9;
int t4;
size_t t8;
int*** A;
int** C4;
scalar_t__ N;
int lb1;
int*** sum;

#pragma scop
#pragma omp parallel for shared(lb1,ub1) private(t0, t1, t2,t3, t4, t5,t6,t7, t8, t9)
for (t0=lb1; t0<=ub1; t0++) {
for (t1=0;t1<=42;t1++) {
for (t3=0;t3<=42;t3++) {
for (t5=42;t5<=42;t5++) {
for (t6=42;t6<=42;t6++) {
for (t9=42;t9<=42;t9++) {
{sum[t5][t6 ][ t9]=0;} ;
}
}
}
}
for (t3=0;t3<=42;t3++) {
for (t4=0;t4<=42;t4++) {
for (t5=42;t5<=42;t5++) {
for (t6=42;t6<=42;t6++) {
for (t8=42;t8<=42;t8++) {
for (t9=42;t9<=42;t9++) {
{sum[t5][t6 ][ t9]=A[t5][t6 ][ t8]*C4[t8][ t9]+sum[t5][t6 ][ t9 ];} ;
}
}
}
}
}
}
for (t3=0;t3<=42;t3++) {
for (t5=42;t5<=42;t5++) {
for (t6=42;t6<=42;t6++) {
for (t9=42;t9<=42;t9++) {
{A[t5][ t6 ][ t9]=sum[t5][t6 ][ t9 ];} ;
}
}
}
}
}
}

#pragma endscop
printf("The value of A is %p", A);
printf("The value of C4 is %p", C4);
printf("The value of sum is %p", sum);

return 0;
}