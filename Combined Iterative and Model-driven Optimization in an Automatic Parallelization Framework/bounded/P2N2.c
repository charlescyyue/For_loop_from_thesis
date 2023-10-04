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
size_t i2;
size_t j2;
size_t k2;
int** C;
scalar_t__** D;
int** tmp;

#pragma scop
for (i2 = 0; i2 < N; ++i2)
for (j2 = 0; j2 < N; ++j2) {
 D[i2][j2] = 0;
for (k2 = 0; k2 < N; ++k2)
 D[i2][j2] += tmp[i2][k2] * C[k2][j2];
}

#pragma endscop
printf("The value of C is %p", C);
printf("The value of D is %p", D);
printf("The value of tmp is %p", tmp);

return 0;
}