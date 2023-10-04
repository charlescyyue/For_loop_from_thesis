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
scalar_t__ i;
scalar_t__ v;
scalar_t__ h;
scalar_t__ j;

#pragma scop
for (v = 0; v < N; v++)
for (h = 0; h < N; h++)
{
#1 s = 0;
for (i = 0; i < K; i++)
{
#2 v_s = 0;
for (j = 0; j < K; j+=4)
{
#3simd_loadu(v_1,&image[v+i][h+j]);
#4 simd_load(v_2,&filter[i][j]);
#5 v_3=simd_vmuls(v_1,v_2);
#6 v_s=simd_vadds(v_s,v_3);
}
#7s=s+simd_vextf0(v_s)+simd_vextf1(v_s)+sim d_vextf2(v_s)+simd_vextf3(v_s);
}
#8 out[v][h] = s ;
}

#pragma endscop

return 0;
}