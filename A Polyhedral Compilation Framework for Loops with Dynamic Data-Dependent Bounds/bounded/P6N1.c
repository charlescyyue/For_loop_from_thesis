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

#if !defined(I) && !defined(BB) && !defined(CC)
# ifdef DATASET_XS
# define I 16
# define BB 16
# define CC 16
#endif

# ifdef DATASET_S
# define I 64
# define BB 64
# define CC 64
#endif

# ifdef DATASET_M
# define I 256
# define BB 256
# define CC 256
#endif

# ifdef DATASET_L
# define I 1024
# define BB 1024
# define CC 1024
#endif

# ifdef DATASET_XL
# define I 4096
# define BB 4096
# define CC 4096
#endif

# ifdef DATASET_XXL
# define I 16384
# define BB 16384
# define CC 16384
#endif

# ifdef DATASET_XXXL
# define I 65536
# define BB 65536
# define CC 65536
#endif

#endif


int main(){
int i;
int m;
int n;
size_t j;
int jj;
size_t k;
int kk;
int***** A;

#pragma scop
for (i=0; i<100*I; i++) {
m = 33*i+42;
n = 75*i+13;
for (jj=0; jj<m/BB+1; jj++)
for (kk=0; kk<n/CC+1; kk++)
for (j=0; j<42; j++)
for (k=0; k<42; k++)
A[i][jj][kk][j][k] = i - jj + kk - j + k;
}

#pragma endscop
printf("The value of A is %p", A);

return 0;
}