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

#if !defined(len_0)
# ifdef DATASET_XS
# define len_0 16
#endif

# ifdef DATASET_S
# define len_0 64
#endif

# ifdef DATASET_M
# define len_0 256
#endif

# ifdef DATASET_L
# define len_0 1024
#endif

# ifdef DATASET_XL
# define len_0 4096
#endif

# ifdef DATASET_XXL
# define len_0 16384
#endif

# ifdef DATASET_XXXL
# define len_0 65536
#endif

#endif


int main(){
size_t i;
scalar_t__* band_0;
size_t len_0_0;

#pragma scop
for(i = 0; i < len_0; i++) {
band_0[i] = (* band_0 + len_0_0 * i);
}

#pragma endscop
printf("The value of band_0 is %p", band_0);

return 0;
}