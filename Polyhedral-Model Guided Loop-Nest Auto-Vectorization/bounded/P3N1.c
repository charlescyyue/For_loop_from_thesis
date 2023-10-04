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

#if !defined(N) && !defined(K)
# ifdef DATASET_XS
# define N 16
# define K 16
#endif

# ifdef DATASET_S
# define N 64
# define K 64
#endif

# ifdef DATASET_M
# define N 256
# define K 256
#endif

# ifdef DATASET_L
# define N 1024
# define K 1024
#endif

# ifdef DATASET_XL
# define N 4096
# define K 4096
#endif

# ifdef DATASET_XXL
# define N 16384
# define K 16384
#endif

# ifdef DATASET_XXXL
# define N 65536
# define K 65536
#endif

#endif


int main(){
size_t i;
size_t v;
size_t h;
size_t j;
int factor;
int** filter;
int** image;
int** out;
int s;

#pragma scop
for (v = 0; v < N; v++)
for (h = 0; h < N; h++) {
 s = 0;
for (i = 0; i < K; i++)
for (j = 0; j < K; j++)
 s += image[v+i][h+j] * filter[i][j];
 out[v][h] = s >> factor;}

#pragma endscop
printf("The value of filter is %p", filter);
printf("The value of image is %p", image);
printf("The value of out is %p", out);

return 0;
}