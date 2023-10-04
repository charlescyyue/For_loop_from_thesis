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

#if !defined(lag_min) && !defined(L_frame)
# ifdef DATASET_XS
# define lag_min 16
# define L_frame 16
#endif

# ifdef DATASET_S
# define lag_min 64
# define L_frame 64
#endif

# ifdef DATASET_M
# define lag_min 256
# define L_frame 256
#endif

# ifdef DATASET_L
# define lag_min 1024
# define L_frame 1024
#endif

# ifdef DATASET_XL
# define lag_min 4096
# define L_frame 4096
#endif

# ifdef DATASET_XXL
# define lag_min 16384
# define L_frame 16384
#endif

# ifdef DATASET_XXXL
# define lag_min 65536
# define L_frame 65536
#endif

#endif


int main(){
size_t i;
size_t j;
size_t lag_max;
int max;
size_t p_max;
int* scal_sig;

#pragma scop
for (i = lag_max; i >= lag_min; i--) {
int t0 = 0;
for (j = 0; j < L_frame; j++) {
t0 = t0 + scal_sig[j] * scal_sig[j-i];
}
if ((t0 - max) >= 0) {
max = t0;
p_max = i;
}
}

#pragma endscop
printf("The value of scal_sig is %p", scal_sig);

return 0;
}