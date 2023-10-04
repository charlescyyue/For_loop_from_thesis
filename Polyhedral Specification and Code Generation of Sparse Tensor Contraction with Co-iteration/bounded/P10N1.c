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
struct TYPE_2__ {int numRows; int* rowPtr; size_t* rowIdx; int* data; size_t* colIdx; } ;


# if !defined(DATASET_XS) && !defined(DATASET_S) && !defined(DATASET_M) && !defined(DATASET_L) && !defined(DATASET_XL) && !defined(DATASET_XXL) && !defined(DATASET_XXXL)
# define DATASET_M
# endif

#if !defined(A)
# ifdef DATASET_XS
# define A 16
#endif

# ifdef DATASET_S
# define A 64
#endif

# ifdef DATASET_M
# define A 256
#endif

# ifdef DATASET_L
# define A 1024
#endif

# ifdef DATASET_XL
# define A 4096
#endif

# ifdef DATASET_XXL
# define A 16384
#endif

# ifdef DATASET_XXXL
# define A 65536
#endif

#endif


int main(){
TYPE_1__ A;
int j;
int* x;
int* y;

#pragma scop
for (int p_i = 0;p_i < A.numRows; ++p_i)
for (int p_j = A.rowPtr[p_i]; j < A.rowPtr[p_i+1]; ++p_j)
y[A.rowIdx[p_i]] += A.data[p_j] * x[A.colIdx[p_j]];

#pragma endscop
printf("The value of x is %p", x);
printf("The value of y is %p", y);

return 0;
}