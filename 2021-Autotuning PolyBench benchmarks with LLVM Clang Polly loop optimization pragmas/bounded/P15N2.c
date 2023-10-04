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

#if !defined(_PB_N)
# ifdef DATASET_XS
# define _PB_N 16
#endif

# ifdef DATASET_S
# define _PB_N 64
#endif

# ifdef DATASET_M
# define _PB_N 256
#endif

# ifdef DATASET_L
# define _PB_N 1024
#endif

# ifdef DATASET_XL
# define _PB_N 4096
#endif

# ifdef DATASET_XXL
# define _PB_N 16384
#endif

# ifdef DATASET_XXXL
# define _PB_N 65536
#endif

#endif


int main(){
size_t i;
size_t j;
size_t k;
scalar_t__** path;

#pragma scop
for (j = 0; j < _PB_N; j++)
for (k = 0; k < _PB_N; k++)
for(i = _PB_N-1; i >= 0; i--)
path[i][j] = (path[i][j] < path[i][k] + path[k][j]) ? path[i][j]: (path[i][k] + path[k][j]);


#pragma endscop
printf("The value of path is %p", path);

return 0;
}