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

#if !defined(tmax) && !defined(ny) && !defined(nx)
# ifdef DATASET_XS
# define tmax 16
# define ny 16
# define nx 16
#endif

# ifdef DATASET_S
# define tmax 64
# define ny 64
# define nx 64
#endif

# ifdef DATASET_M
# define tmax 256
# define ny 256
# define nx 256
#endif

# ifdef DATASET_L
# define tmax 1024
# define ny 1024
# define nx 1024
#endif

# ifdef DATASET_XL
# define tmax 4096
# define ny 4096
# define nx 4096
#endif

# ifdef DATASET_XXL
# define tmax 16384
# define ny 16384
# define nx 16384
#endif

# ifdef DATASET_XXXL
# define tmax 65536
# define ny 65536
# define nx 65536
#endif

#endif


int main(){
size_t i;
scalar_t__ t;
size_t j;
int coeff0;
int coeff1;
int coeff2;
int** ex;
int** ey;
int** hz;
int t1;

#pragma scop
for ( t=0; t<tmax; t++) {
for ( j=0; j<ny; j++)
ey [0][ j ] = exp(-coeff0*t1);
for ( i=1; i<nx; i++)
for ( j=0; j<ny; j++)
ey[ i ][ j ] = ey[ i ][ j ] - coeff1*(hz[i ][ j]-hz[i-1][j ]);
for ( i=0; i<nx; i++)
for ( j=1; j<ny; j++)
ex[ i ][ j ] = ex[ i ][ j ] - coeff1*(hz[i ][ j]-hz[i][ j-1]);
for ( i=0; i<nx; i++)
for ( j=0; j<ny; j++)
hz[i ][ j ] = hz[i ][ j ] - coeff2*(ex[ i ][ j+1]-ex[i][j ] +ey[i+1][j]-ey[i][ j ]);
}

#pragma endscop
printf("The value of ex is %p", ex);
printf("The value of ey is %p", ey);
printf("The value of hz is %p", hz);

return 0;
}