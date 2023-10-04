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

#if !defined(ubj2)
# ifdef DATASET_XS
# define ubj2 16
#endif

# ifdef DATASET_S
# define ubj2 64
#endif

# ifdef DATASET_M
# define ubj2 256
#endif

# ifdef DATASET_L
# define ubj2 1024
#endif

# ifdef DATASET_XL
# define ubj2 4096
#endif

# ifdef DATASET_XXL
# define ubj2 16384
#endif

# ifdef DATASET_XXXL
# define ubj2 65536
#endif

#endif


int main(){
scalar_t__ j;
scalar_t__ ubj;
scalar_t__ V;
scalar_t__ lbj2;

#pragma scop
for (j = lbj2; j < ubj - ubj2; j += V) {
}

#pragma endscop

return 0;
}