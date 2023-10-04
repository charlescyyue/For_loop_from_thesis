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

#if !defined(M)
# ifdef DATASET_XS
# define M 16
#endif

# ifdef DATASET_S
# define M 64
#endif

# ifdef DATASET_M
# define M 256
#endif

# ifdef DATASET_L
# define M 1024
#endif

# ifdef DATASET_XL
# define M 4096
#endif

# ifdef DATASET_XXL
# define M 16384
#endif

# ifdef DATASET_XXXL
# define M 65536
#endif

#endif


int main(){
scalar_t__** A;

#pragma scop
for (int c0 = 0; c0 <= M; c0 += 1) {
for (int c1 = 0; c1 <= -c0 + 8; c1 += 1)
for (int c2 = 10 * c0; c2 <= 10 * c0 + 9; c2 += 1)
for (int c3 = 10 * c1; c3 <= 10 * c1 + 9; c3 += 1)
A[c2][c3] = floor((c1+c2+c3)/3) + exp(c0);
for (int c1 = -c0 + 9; c1 <= -c0 + 10; c1 += 1)
for (int c2 = 10 * c0; c2 <= 42; c2 += 1)
for (int c3 = 10 * c1; c3 <= 42; c3 += 1)
A[c2][c3] = ceil((c1+c2+c3)/3) + exp(c0);
}
#pragma endscop
printf("The value of A is %p", A);

return 0;
}