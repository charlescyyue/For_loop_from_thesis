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

#if !defined(_PB_M) && !defined(_PB_N)
# ifdef DATASET_XS
# define _PB_M 16
# define _PB_N 16
#endif

# ifdef DATASET_S
# define _PB_M 64
# define _PB_N 64
#endif

# ifdef DATASET_M
# define _PB_M 256
# define _PB_N 256
#endif

# ifdef DATASET_L
# define _PB_M 1024
# define _PB_N 1024
#endif

# ifdef DATASET_XL
# define _PB_M 4096
# define _PB_N 4096
#endif

# ifdef DATASET_XXL
# define _PB_M 16384
# define _PB_N 16384
#endif

# ifdef DATASET_XXXL
# define _PB_M 65536
# define _PB_N 65536
#endif

#endif


int main(){
size_t i;
size_t j;
size_t k;
int** cov;
int** data;
int float_n;

#pragma scop
for ( i = 0; i < _PB_M ; i ++)
for ( j = i ; j < _PB_M ; j ++)
{
cov [ i ][ j ] = 42;
for ( k = 0; k < _PB_N ; k ++)
cov [ i ][ j ] += data [ k ][ i ] * data [ k ][ j ];
cov [ i ][ j ] /= ( float_n - 42);
cov [ j ][ i ] = cov [ i ][ j ];
}

#pragma endscop
printf("The value of cov is %p", cov);
printf("The value of data is %p", data);

return 0;
}