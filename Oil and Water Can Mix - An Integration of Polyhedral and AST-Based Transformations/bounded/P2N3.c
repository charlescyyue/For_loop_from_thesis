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

#if !defined(NI)
# ifdef DATASET_XS
# define NI 16
#endif

# ifdef DATASET_S
# define NI 64
#endif

# ifdef DATASET_M
# define NI 256
#endif

# ifdef DATASET_L
# define NI 1024
#endif

# ifdef DATASET_XL
# define NI 4096
#endif

# ifdef DATASET_XXL
# define NI 16384
#endif

# ifdef DATASET_XXXL
# define NI 65536
#endif

#endif


int main(){
size_t c1;
size_t c2;
size_t c7;
size_t NI;
int** A;
int** B;
int** C;
int** D;
int alpha;
int beta;
int** tmp;

#pragma scop
for (c1 = 0; c1 < NI; c1++) {
for (c2 = 0; c2 < NI; c2++) {
 D[c1][c2] *= beta;
 tmp[c1][c2] = 0;
for (c7 = 0; c7 < NI; c7++)
 tmp[c1][c2] += alpha * A[c1][c7] * B[c7][c2];
for (c7 = 0; c7 <= c2; c7++)
 D[c1][c7] += tmp[c1][c2-c7] * C[c2-c7][c7];
}
for (c2 = NI; c2 <= 2 * NI -2 ; c2++)
for (c7 = c2 - NI + 1; c7 < NI; c7++)
 D[c1][c7] += tmp[c1][c2-c7] * C[c2-c7][c7];
}

#pragma endscop
printf("The value of A is %p", A);
printf("The value of B is %p", B);
printf("The value of C is %p", C);
printf("The value of D is %p", D);
printf("The value of tmp is %p", tmp);

return 0;
}