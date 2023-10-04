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

#if !defined(ni) && !defined(nj)
# ifdef DATASET_XS
# define ni 16
# define nj 16
#endif

# ifdef DATASET_S
# define ni 64
# define nj 64
#endif

# ifdef DATASET_M
# define ni 256
# define nj 256
#endif

# ifdef DATASET_L
# define ni 1024
# define nj 1024
#endif

# ifdef DATASET_XL
# define ni 4096
# define nj 4096
#endif

# ifdef DATASET_XXL
# define ni 16384
# define nj 16384
#endif

# ifdef DATASET_XXXL
# define ni 65536
# define nj 65536
#endif

#endif


int main(){
size_t i;
size_t j;
int** C;
int beta;

#pragma scop
for (i = 0; i < ni; i++)
for (j = 0; j < nj; j++)
 C[i][j] *= beta;

#pragma endscop
printf("The value of C is %p", C);

return 0;
}