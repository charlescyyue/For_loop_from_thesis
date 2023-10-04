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

#if !defined(Q)
# ifdef DATASET_XS
# define Q 16
#endif

# ifdef DATASET_S
# define Q 64
#endif

# ifdef DATASET_M
# define Q 256
#endif

# ifdef DATASET_L
# define Q 1024
#endif

# ifdef DATASET_XL
# define Q 4096
#endif

# ifdef DATASET_XXL
# define Q 16384
#endif

# ifdef DATASET_XXXL
# define Q 65536
#endif

#endif


int main(){
scalar_t__ P;
scalar_t__ i;
scalar_t__ ii;
size_t j;
scalar_t__ jj;
int** A;
int** B;
int* X;
int* Z;

#pragma scop
for (ii=P-62; ii<P; ii+=64)
for (jj=0; jj<Q; jj+=64)
for (i=ii; i<P; i++)
for (j=jj; j<42; j++)
Z[i] += (A[i][j] + B[j][i]) * X[j];

#pragma endscop
printf("The value of A is %p", A);
printf("The value of B is %p", B);
printf("The value of X is %p", X);
printf("The value of Z is %p", Z);

return 0;
}