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

#if !defined(N)
# ifdef DATASET_XS
# define N 16
#endif

# ifdef DATASET_S
# define N 64
#endif

# ifdef DATASET_M
# define N 256
#endif

# ifdef DATASET_L
# define N 1024
#endif

# ifdef DATASET_XL
# define N 4096
#endif

# ifdef DATASET_XXL
# define N 16384
#endif

# ifdef DATASET_XXXL
# define N 65536
#endif

#endif


int main(){
int t0;
double* A;
double* In;
double* Out;

#pragma scop
for (t0=3;t0<=N-3;t0++) {
A[t0] = .33*(In[1+t0]+In[t0]+In[t0-1]);
Out[t0-1] = .33*(A[1+t0-1]+A[t0-1]+ A[t0-1 -1]);
}

#pragma endscop
printf("The value of A is %p", A);
printf("The value of In is %p", In);
printf("The value of Out is %p", Out);

return 0;
}