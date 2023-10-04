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
size_t i;
scalar_t__* x;
scalar_t__* z;

#pragma scop
for (i = 0; i < M; i++)
 x[i] = x[i] + z[i];

#pragma endscop
printf("The value of x is %p", x);
printf("The value of z is %p", z);

return 0;
}