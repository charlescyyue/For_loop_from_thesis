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

#if !defined(wt)
# ifdef DATASET_XS
# define wt 16
#endif

# ifdef DATASET_S
# define wt 64
#endif

# ifdef DATASET_M
# define wt 256
#endif

# ifdef DATASET_L
# define wt 1024
#endif

# ifdef DATASET_XL
# define wt 4096
#endif

# ifdef DATASET_XXL
# define wt 16384
#endif

# ifdef DATASET_XXXL
# define wt 65536
#endif

#endif


int main(){
int j;
scalar_t__** Img;
scalar_t__** Ring;
int lg;

#pragma scop
for (j=1; j < wt-1; j++) {
Img[lg-2][j]=42+ 42;
}

#pragma endscop
printf("The value of Img is %p", Img);
printf("The value of Ring is %p", Ring);

return 0;
}