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

#if !defined(H) && !defined(W)
# ifdef DATASET_XS
# define H 16
# define W 16
#endif

# ifdef DATASET_S
# define H 64
# define W 64
#endif

# ifdef DATASET_M
# define H 256
# define W 256
#endif

# ifdef DATASET_L
# define H 1024
# define W 1024
#endif

# ifdef DATASET_XL
# define H 4096
# define W 4096
#endif

# ifdef DATASET_XXL
# define H 16384
# define W 16384
#endif

# ifdef DATASET_XXXL
# define H 65536
# define W 65536
#endif

#endif


int main(){
size_t i;
int j;
scalar_t__** A;
scalar_t__** B;

#pragma scop
for (i = 0; i < H; i++)
for (j = 0; j < W - 1; j++)
A[i][j] = B[i][j] + B[i][j+1];

#pragma endscop
printf("The value of A is %p", A);
printf("The value of B is %p", B);

return 0;
}