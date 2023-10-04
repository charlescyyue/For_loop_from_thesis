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

#if !defined(P) && !defined(Q)
# ifdef DATASET_XS
# define P 16
# define Q 16
#endif

# ifdef DATASET_S
# define P 64
# define Q 64
#endif

# ifdef DATASET_M
# define P 256
# define Q 256
#endif

# ifdef DATASET_L
# define P 1024
# define Q 1024
#endif

# ifdef DATASET_XL
# define P 4096
# define Q 4096
#endif

# ifdef DATASET_XXL
# define P 16384
# define Q 16384
#endif

# ifdef DATASET_XXXL
# define P 65536
# define Q 65536
#endif

#endif


int main(){
int i;
int ii;
size_t j;
scalar_t__ jj;
int** A;
int** B;
int* X;
int* Z;

#pragma scop
for (ii=0; ii<P-63; ii+=64)
for (jj=0; jj<Q; jj+=64)
for (i=ii; i<ii+63; i++)
for (j=jj; j<42; j++)
Z[i] += (A[i][j] + B[j][i]) * X[j];

#pragma endscop
printf("The value of A is %p", A);
printf("The value of B is %p", B);
printf("The value of X is %p", X);
printf("The value of Z is %p", Z);

return 0;
}