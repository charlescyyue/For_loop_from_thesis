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

#if !defined(NI) && !defined(NJ) && !defined(NK)
# ifdef DATASET_XS
# define NI 16
# define NJ 16
# define NK 16
#endif

# ifdef DATASET_S
# define NI 64
# define NJ 64
# define NK 64
#endif

# ifdef DATASET_M
# define NI 256
# define NJ 256
# define NK 256
#endif

# ifdef DATASET_L
# define NI 1024
# define NJ 1024
# define NK 1024
#endif

# ifdef DATASET_XL
# define NI 4096
# define NJ 4096
# define NK 4096
#endif

# ifdef DATASET_XXL
# define NI 16384
# define NJ 16384
# define NK 16384
#endif

# ifdef DATASET_XXXL
# define NI 65536
# define NJ 65536
# define NK 65536
#endif

#endif


int main(){
size_t i;
size_t j;
size_t k;
int** A;
int** B;
int alpha;
scalar_t__** tmp;

#pragma scop
for (i = 0; i < NI; i++) {
for (j = 0; j < NJ; j++) {
 tmp[i][j] = 0;
for (k = 0; k < NK; k++)
 tmp[i][j] += alpha * A[i][k] * B[k][j];
}
}

#pragma endscop
printf("The value of A is %p", A);
printf("The value of B is %p", B);
printf("The value of tmp is %p", tmp);

return 0;
}