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

#if !defined(M) && !defined(N) && !defined(P)
# ifdef DATASET_XS
# define M 16
# define N 16
# define P 16
#endif

# ifdef DATASET_S
# define M 64
# define N 64
# define P 64
#endif

# ifdef DATASET_M
# define M 256
# define N 256
# define P 256
#endif

# ifdef DATASET_L
# define M 1024
# define N 1024
# define P 1024
#endif

# ifdef DATASET_XL
# define M 4096
# define N 4096
# define P 4096
#endif

# ifdef DATASET_XXL
# define M 16384
# define N 16384
# define P 16384
#endif

# ifdef DATASET_XXXL
# define M 65536
# define N 65536
# define P 65536
#endif

#endif


int main(){
size_t i;
size_t j;
size_t k;
int** A;
int** B;
int** C;
int alp;

#pragma scop
for (i = 0; i < M; i++)
for (j = 0; j < N; j++)
for (k = 0; k < P; k++)
 C[i][j] += alp * A[i][k] * B[k][j];

#pragma endscop
printf("The value of A is %p", A);
printf("The value of B is %p", B);
printf("The value of C is %p", C);

return 0;
}