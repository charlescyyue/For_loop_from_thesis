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

#if !defined(I)
# ifdef DATASET_XS
# define I 16
#endif

# ifdef DATASET_S
# define I 64
#endif

# ifdef DATASET_M
# define I 256
#endif

# ifdef DATASET_L
# define I 1024
#endif

# ifdef DATASET_XL
# define I 4096
#endif

# ifdef DATASET_XXL
# define I 16384
#endif

# ifdef DATASET_XXXL
# define I 65536
#endif

#endif


int main(){
int** A;
scalar_t__* c;
int* x;

#pragma scop
for (int i = 0; i < I; i++) {
c[i] = 0;
for (int j = i; j < I; j++) {
c[i] = c[i] + A[i][j] * x[j];
}
}

#pragma endscop
printf("The value of A is %p", A);
printf("The value of c is %p", c);
printf("The value of x is %p", x);

return 0;
}