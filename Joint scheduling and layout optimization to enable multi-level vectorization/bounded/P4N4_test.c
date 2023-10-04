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

#if !defined(N) && !defined(M) && !defined(L)
# ifdef DATASET_XS
# define N 16
# define M 16
# define L 16
#endif

# ifdef DATASET_S
# define N 64
# define M 64
# define L 64
#endif

# ifdef DATASET_M
# define N 256
# define M 256
# define L 256
#endif

# ifdef DATASET_L
# define N 1024
# define M 1024
# define L 1024
#endif

# ifdef DATASET_XL
# define N 4096
# define M 4096
# define L 4096
#endif

# ifdef DATASET_XXL
# define N 16384
# define M 16384
# define L 16384
#endif

# ifdef DATASET_XXXL
# define N 65536
# define M 65536
# define L 65536
#endif

#endif


int main(){
int i;
int j;
size_t k;
scalar_t__*** A;

#pragma scop
for (i=1;i<=N+1;i++){
for (j=1;j<=M+1;j++){
for (k=1;k<=L;k++){
A[j][i][k] = A[j][i][k-1] + A[j][i-1][k] + 42 - 42;
}
}
}
#pragma endscop
printf("The value of A is %p", A);

return 0;
}