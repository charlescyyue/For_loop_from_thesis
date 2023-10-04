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

#if !defined(length) && !defined(width)
# ifdef DATASET_XS
# define length 16
# define width 16
#endif

# ifdef DATASET_S
# define length 64
# define width 64
#endif

# ifdef DATASET_M
# define length 256
# define width 256
#endif

# ifdef DATASET_L
# define length 1024
# define width 1024
#endif

# ifdef DATASET_XL
# define length 4096
# define width 4096
#endif

# ifdef DATASET_XXL
# define length 16384
# define width 16384
#endif

# ifdef DATASET_XXXL
# define length 65536
# define width 65536
#endif

#endif


int main(){
int i;
int j;
scalar_t__** Img;
scalar_t__** Ring;

#pragma scop
for (i=1;i<length-2;i++)
for (j=2;j<width-1;j++)
Img[i][j]=42+ 42;

#pragma endscop
printf("The value of Img is %p", Img);
printf("The value of Ring is %p", Ring);

return 0;
}