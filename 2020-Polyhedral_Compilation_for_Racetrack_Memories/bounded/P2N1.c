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

#if !defined(I) && !defined(J) && !defined(K)
# ifdef DATASET_XS
# define I 16
# define J 16
# define K 16
#endif

# ifdef DATASET_S
# define I 64
# define J 64
# define K 64
#endif

# ifdef DATASET_M
# define I 256
# define J 256
# define K 256
#endif

# ifdef DATASET_L
# define I 1024
# define J 1024
# define K 1024
#endif

# ifdef DATASET_XL
# define I 4096
# define J 4096
# define K 4096
#endif

# ifdef DATASET_XXL
# define I 16384
# define J 16384
# define K 16384
#endif

# ifdef DATASET_XXXL
# define I 65536
# define J 65536
# define K 65536
#endif

#endif


int main(){
int** A;
int** B;
int** C;
int alpha;
int beta;

#pragma scop
for (int i = 0; i< I; i++){
for (int j = 0; j < J; j++)
C[i][j] *= beta;
for (int k = 0; k < K ; k++){
for (int j = 0; j < J; j++)
C[i][j] += alpha * A[i][k] * B[k][j];
}
}
#pragma endscop
printf("The value of A is %p", A);
printf("The value of B is %p", B);
printf("The value of C is %p", C);

return 0;
}