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

#if !defined(ubi) && !defined(ubj)
# ifdef DATASET_XS
# define ubi 16
# define ubj 16
#endif

# ifdef DATASET_S
# define ubi 64
# define ubj 64
#endif

# ifdef DATASET_M
# define ubi 256
# define ubj 256
#endif

# ifdef DATASET_L
# define ubi 1024
# define ubj 1024
#endif

# ifdef DATASET_XL
# define ubi 4096
# define ubj 4096
#endif

# ifdef DATASET_XXL
# define ubi 16384
# define ubj 16384
#endif

# ifdef DATASET_XXXL
# define ubi 65536
# define ubj 65536
#endif

#endif


int main(){
size_t i;
size_t j;
scalar_t__** A;
scalar_t__** B;
size_t lbi;
size_t lbj;

#pragma scop
for (i = lbi; i < ubi; ++i)
for (j = lbj; j < ubj; ++j)
A[i][j] = B[ i ][j+1] + B[ i ][ j ] + B[i-1][ j ];

#pragma endscop
printf("The value of A is %p", A);
printf("The value of B is %p", B);

return 0;
}