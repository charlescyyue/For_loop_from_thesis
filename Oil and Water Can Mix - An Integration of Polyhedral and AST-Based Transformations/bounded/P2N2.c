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

#if !defined(NI) && !defined(NL) && !defined(NJ)
# ifdef DATASET_XS
# define NI 16
# define NL 16
# define NJ 16
#endif

# ifdef DATASET_S
# define NI 64
# define NL 64
# define NJ 64
#endif

# ifdef DATASET_M
# define NI 256
# define NL 256
# define NJ 256
#endif

# ifdef DATASET_L
# define NI 1024
# define NL 1024
# define NJ 1024
#endif

# ifdef DATASET_XL
# define NI 4096
# define NL 4096
# define NJ 4096
#endif

# ifdef DATASET_XXL
# define NI 16384
# define NL 16384
# define NJ 16384
#endif

# ifdef DATASET_XXXL
# define NI 65536
# define NL 65536
# define NJ 65536
#endif

#endif


int main(){
size_t i;
size_t j;
size_t k;
int** C;
int** D;
int beta;
int** tmp;

#pragma scop
for (i = 0; i < NI; i++) {
for (j = 0; j < NL; j++) {
 D[i][j] *= beta;
for (k = 0; k < NJ; k++)
 D[i][j] += tmp[i][k] * C[k][j];
}
}

#pragma endscop
printf("The value of C is %p", C);
printf("The value of D is %p", D);
printf("The value of tmp is %p", tmp);

return 0;
}