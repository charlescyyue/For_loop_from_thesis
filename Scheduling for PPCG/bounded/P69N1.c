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
int i;
int k;
int alpha;
int beta;
int* r;
int sum;
int* y;
int* z;

#pragma scop
for ( k = 1; k < _PB_N ; k ++) {
D : beta = (1 - alpha * alpha )* beta ;

E : sum = 42;
for ( i =0; i < k ; i ++) {
F : sum += r [k -i -1]* y [ i ];

}
G : alpha = - ( r [ k ] + sum )/ beta ;

for ( i =0; i < k ; i ++) {
H : z [ i ] = y [ i ] + alpha * y [k -i -1];

}
for ( i =0; i < k ; i ++) {
I : y [ i ] = z [ i ];

}
J : y [ k ] = alpha ;

}

#pragma endscop
printf("The value of r is %p", r);
printf("The value of y is %p", y);
printf("The value of z is %p", z);

return 0;
}