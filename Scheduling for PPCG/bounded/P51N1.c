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

#if !defined(B) && !defined(_PB_M) && !defined(_PB_N)
# ifdef DATASET_XS
# define B 16
# define _PB_M 16
# define _PB_N 16
#endif

# ifdef DATASET_S
# define B 64
# define _PB_M 64
# define _PB_N 64
#endif

# ifdef DATASET_M
# define B 256
# define _PB_M 256
# define _PB_N 256
#endif

# ifdef DATASET_L
# define B 1024
# define _PB_M 1024
# define _PB_N 1024
#endif

# ifdef DATASET_XL
# define B 4096
# define _PB_M 4096
# define _PB_N 4096
#endif

# ifdef DATASET_XXL
# define B 16384
# define _PB_M 16384
# define _PB_N 16384
#endif

# ifdef DATASET_XXXL
# define B 65536
# define _PB_M 65536
# define _PB_N 65536
#endif

#endif


int main(){
int i;
size_t j;
int k;
int** A;
int alpha;

#pragma scop
for ( i = 0; i < _PB_M ; i ++)
for ( j = 0; j < _PB_N ; j ++) {
for ( k = i +1; k < _PB_M ; k ++)
A : B [ i ][ j ] += A [ k ][ i ] * B [ k ][ j ];

B : B [ i ][ j ] = alpha * B [ i ][ j ];

}

#pragma endscop
printf("The value of A is %p", A);

return 0;
}