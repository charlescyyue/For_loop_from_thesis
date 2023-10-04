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
size_t c0;
size_t c1;
size_t c6;
size_t N;
int** A;
int** B;
int** C;
scalar_t__** D;
int** tmp;

#pragma scop
for (c0 = 0; c0 < N; c0++) {
for (c1 = 0; c1 < N; c1++) {
 tmp[c0][c1]=0;
 D[c0][c1]=0;
for (c6 = 0; c6 < N; c6++)
 tmp[c0][c1] += A[c0][c6] * B[c6][c1];
for (c6 = 0;c6 <= c1; c6++)
 D[c0][c6] += tmp[c0][c1-c6] * C[c1-c6][c6];
}
for (c1 = N; c1 < 2*N - 1; c1++)
for (c6 = c1-N+1; c6 < N; c6++)
 D[c0][c6] += tmp[c0][c1-c6] * C[c1-c6][c6];
}

#pragma endscop
printf("The value of A is %p", A);
printf("The value of B is %p", B);
printf("The value of C is %p", C);
printf("The value of D is %p", D);
printf("The value of tmp is %p", tmp);

return 0;
}