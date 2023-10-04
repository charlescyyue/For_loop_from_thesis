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

#if !defined(M) && !defined(N)
# ifdef DATASET_XS
# define M 16
# define N 16
#endif

# ifdef DATASET_S
# define M 64
# define N 64
#endif

# ifdef DATASET_M
# define M 256
# define N 256
#endif

# ifdef DATASET_L
# define M 1024
# define N 1024
#endif

# ifdef DATASET_XL
# define M 4096
# define N 4096
#endif

# ifdef DATASET_XXL
# define M 16384
# define N 16384
#endif

# ifdef DATASET_XXXL
# define M 65536
# define N 65536
#endif

#endif


int main(){
int** A;
int** B;

#pragma scop
for ( int c0 = 0; c0 < M - 1; c0 += 2) {
for ( int c1 = 0; c1 < N - 1; c1 += 2) {
B[ c0 ][ c1 ] = A[ c1 ][ c0 ];
B[ c0 ][ c1 + 1] = A[ c1 + 1][ c0 ];
}
for ( int c1 = 0; c1 < N - 1; c1 += 2) {
B[ c0 + 1][ c1 ] = A[ c1 ][ c0 + 1];
B[ c0 + 1][ c1 + 1] = A[ c1 + 1][ c0 + 1];
}
}

#pragma endscop
printf("The value of A is %p", A);
printf("The value of B is %p", B);

return 0;
}