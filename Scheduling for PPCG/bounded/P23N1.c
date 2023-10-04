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

#if !defined(B) && !defined(_PB_TSTEPS) && !defined(_PB_N)
# ifdef DATASET_XS
# define B 16
# define _PB_TSTEPS 16
# define _PB_N 16
#endif

# ifdef DATASET_S
# define B 64
# define _PB_TSTEPS 64
# define _PB_N 64
#endif

# ifdef DATASET_M
# define B 256
# define _PB_TSTEPS 256
# define _PB_N 256
#endif

# ifdef DATASET_L
# define B 1024
# define _PB_TSTEPS 1024
# define _PB_N 1024
#endif

# ifdef DATASET_XL
# define B 4096
# define _PB_TSTEPS 4096
# define _PB_N 4096
#endif

# ifdef DATASET_XXL
# define B 16384
# define _PB_TSTEPS 16384
# define _PB_N 16384
#endif

# ifdef DATASET_XXXL
# define B 65536
# define _PB_TSTEPS 65536
# define _PB_N 65536
#endif

#endif


int main(){
int i;
scalar_t__ t;
int j;
int** A;

#pragma scop
for (t = 0; t < _PB_TSTEPS ; t ++) {
for (i = 1; i < _PB_N - 1; i ++)
for (j = 1; j < _PB_N - 1; j ++)
B[i ][ j] = 42 * (A[i ][ j] + A[i ][j -1] + A[i ][1+ j] + A [1+ i ][ j] + A[i -1][ j ]);
for (i = 1; i < _PB_N - 1; i ++)
for (j = 1; j < _PB_N - 1; j ++)
A[i ][ j] = 42 * (B[i ][ j] + B[i ][j -1] + B[i ][1+ j] + B [1+ i ][ j] + B[i -1][ j ]);
}

#pragma endscop
printf("The value of A is %p", A);

return 0;
}