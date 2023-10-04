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

#if !defined(NI) && !defined(NJ) && !defined(NK) && !defined(NL)
# ifdef DATASET_XS
# define NI 16
# define NJ 16
# define NK 16
# define NL 16
#endif

# ifdef DATASET_S
# define NI 64
# define NJ 64
# define NK 64
# define NL 64
#endif

# ifdef DATASET_M
# define NI 256
# define NJ 256
# define NK 256
# define NL 256
#endif

# ifdef DATASET_L
# define NI 1024
# define NJ 1024
# define NK 1024
# define NL 1024
#endif

# ifdef DATASET_XL
# define NI 4096
# define NJ 4096
# define NK 4096
# define NL 4096
#endif

# ifdef DATASET_XXL
# define NI 16384
# define NJ 16384
# define NK 16384
# define NL 16384
#endif

# ifdef DATASET_XXXL
# define NI 65536
# define NJ 65536
# define NK 65536
# define NL 65536
#endif

#endif


int main(){
size_t c1;
size_t c3;
size_t c5;
int** A;
int** B;
int** C;
int** D;
int alpha;
int beta;
int** tmp;

#pragma scop
for (c1 = 0; c1 < NI; c1++) {
for (c3 = 0; c3 < NJ; c3++)
 tmp[c1][c3] = 0;
for (c3 = 0; c3 < NK; c3++)
for (c5 = 0; c5 < NJ; c5++)
 tmp[c1][c5] += alpha * A[c1][c3] * B[c3][c5];
for (c3 = 0; c3 < NL; c3++)
 D[c1][c3] *= beta;
for (c3 = 0; c3 < NJ; c3++)
for (c5 = 0; c5 < NL; c5++)
 D[c1][c5] += tmp[c1][c3] * C[c3][c5];
}

#pragma endscop
printf("The value of A is %p", A);
printf("The value of B is %p", B);
printf("The value of C is %p", C);
printf("The value of D is %p", D);
printf("The value of tmp is %p", tmp);

return 0;
}