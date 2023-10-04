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

#if !defined(_PB_NITER) && !defined(_PB_MAXGRID) && !defined(_PB_LENGTH)
# ifdef DATASET_XS
# define _PB_NITER 16
# define _PB_MAXGRID 16
# define _PB_LENGTH 16
#endif

# ifdef DATASET_S
# define _PB_NITER 64
# define _PB_MAXGRID 64
# define _PB_LENGTH 64
#endif

# ifdef DATASET_M
# define _PB_NITER 256
# define _PB_MAXGRID 256
# define _PB_LENGTH 256
#endif

# ifdef DATASET_L
# define _PB_NITER 1024
# define _PB_MAXGRID 1024
# define _PB_LENGTH 1024
#endif

# ifdef DATASET_XL
# define _PB_NITER 4096
# define _PB_MAXGRID 4096
# define _PB_LENGTH 4096
#endif

# ifdef DATASET_XXL
# define _PB_NITER 16384
# define _PB_MAXGRID 16384
# define _PB_LENGTH 16384
#endif

# ifdef DATASET_XXXL
# define _PB_NITER 65536
# define _PB_MAXGRID 65536
# define _PB_LENGTH 65536
#endif

#endif


int main(){
int i;
scalar_t__ t;
int j;
int cnt;
scalar_t__*** diff;
scalar_t__** mean;
scalar_t__** path;
scalar_t__*** sum_diff;
scalar_t__** sum_tang;

#pragma scop
for ( t = 0; t < _PB_NITER ; t ++) {
for ( j = 0; j <= _PB_MAXGRID - 1; j ++)
for ( i = j ; i <= _PB_MAXGRID - 1; i ++)
for ( cnt = 0; cnt <= _PB_LENGTH - 1; cnt ++)
diff [ j ][ i ][ cnt ] = sum_tang [ j ][ i ];
for ( j = 0; j <= _PB_MAXGRID - 1; j ++) {
for ( i = j ; i <= _PB_MAXGRID - 1; i ++) {
sum_diff [ j ][ i ][0] = diff [ j ][ i ][0];
for ( cnt = 1; cnt <= _PB_LENGTH - 1; cnt ++)
sum_diff [ j ][ i ][ cnt ] = sum_diff [ j ][ i ][ cnt - 1] + diff [ j ][ i ][ cnt ];
mean [ j ][ i ] = sum_diff [ j ][ i ][ _PB_LENGTH - 1];
}
}
for ( i = 0; i <= _PB_MAXGRID - 1; i ++)
path [0][ i ] = mean [0][ i ];
for ( j = 1; j <= _PB_MAXGRID - 1; j ++)
for ( i = j ; i <= _PB_MAXGRID - 1; i ++)
path [ j ][ i ] = path [ j - 1][ i - 1] + mean [ j ][ i ];
}

#pragma endscop
printf("The value of diff is %p", diff);
printf("The value of mean is %p", mean);
printf("The value of path is %p", path);
printf("The value of sum_diff is %p", sum_diff);
printf("The value of sum_tang is %p", sum_tang);

return 0;
}