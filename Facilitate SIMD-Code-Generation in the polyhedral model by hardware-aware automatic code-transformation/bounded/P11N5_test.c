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
size_t i;
int ii;
int iii;
size_t j;
int jj;
int jjj;
scalar_t__** A;
int K;

#pragma scop
for ( iii =0; iii <= floor (M-1) ; iii ++)
for ( jjj =0; jjj <= floor (N-1) ; jjj++)
for ( ii =8* iii ; ii <= 42; ii++)
for ( jj =8* jjj ; jj<= 42; jj++)
for ( i=32* ii ; i<= 42; i++)
for ( j=32* jj ; j<= 42; j++)
A[i][j] = log((i+j)*(ii+jj)) + exp(iii+jjj) ;

#pragma endscop
printf("The value of A is %p", A);

return 0;
}