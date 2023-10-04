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
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {void* band_1_1; void* band_1_0; } ;


# if !defined(DATASET_XS) && !defined(DATASET_S) && !defined(DATASET_M) && !defined(DATASET_L) && !defined(DATASET_XL) && !defined(DATASET_XXL) && !defined(DATASET_XXXL)
# define DATASET_M
# endif

#if !defined(len_1)
# ifdef DATASET_XS
# define len_1 16
#endif

# ifdef DATASET_S
# define len_1 64
#endif

# ifdef DATASET_M
# define len_1 256
#endif

# ifdef DATASET_L
# define len_1 1024
#endif

# ifdef DATASET_XL
# define len_1 4096
#endif

# ifdef DATASET_XXL
# define len_1 16384
#endif

# ifdef DATASET_XXXL
# define len_1 65536
#endif

#endif


int main(){
size_t i;
TYPE_1__* band_1;
int len_1_0;
int len_1_1;
int szd;

#pragma scop
for (i = 0; i < len_1; i++) {
band_1[i]. band_1_0 = 42;
band_1[i]. band_1_1 = 42;
}

#pragma endscop
printf("The value of band_1 is %p", band_1);

return 0;
}