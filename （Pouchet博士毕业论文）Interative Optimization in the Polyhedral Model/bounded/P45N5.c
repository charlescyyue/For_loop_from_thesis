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
size_t t1;
size_t t3;
size_t t5;
int** C;
int** D;
int** E;
int** F;
int** G;

#pragma scop
for (t1 = 0; t1 < N; ++t1)
for (t3 = 0; t3 < N; ++t3) {
for (t5 = 0; t5 < N; ++t5)
F[t3][t1] += D[t3][t5] * E[t5][t1];
for (t5 = 0; t5 < N; ++t5)
G[t5][t1] += C[t5][t3] * F[t3][t1];
}

#pragma endscop
printf("The value of C is %p", C);
printf("The value of D is %p", D);
printf("The value of E is %p", E);
printf("The value of F is %p", F);
printf("The value of G is %p", G);

return 0;
}