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

#if !defined(T) && !defined(N)
# ifdef DATASET_XS
# define T 16
# define N 16
#endif

# ifdef DATASET_S
# define T 64
# define N 64
#endif

# ifdef DATASET_M
# define T 256
# define N 256
#endif

# ifdef DATASET_L
# define T 1024
# define N 1024
#endif

# ifdef DATASET_XL
# define T 4096
# define N 4096
#endif

# ifdef DATASET_XXL
# define T 16384
# define N 16384
#endif

# ifdef DATASET_XXXL
# define T 65536
# define N 65536
#endif

#endif


int main(){
int c1;
int c2;

#pragma scop
for (c1=0;c1<=T-1;c1++) {
for (c2=2*c1+3;c2<=2*c1+N-2;c2++) {
}
}

#pragma endscop

return 0;
}