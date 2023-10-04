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

#if !defined(N) && !defined(M)
# ifdef DATASET_XS
# define N 16
# define M 16
#endif

# ifdef DATASET_S
# define N 64
# define M 64
#endif

# ifdef DATASET_M
# define N 256
# define M 256
#endif

# ifdef DATASET_L
# define N 1024
# define M 1024
#endif

# ifdef DATASET_XL
# define N 4096
# define M 4096
#endif

# ifdef DATASET_XXL
# define N 16384
# define M 16384
#endif

# ifdef DATASET_XXXL
# define N 65536
# define M 65536
#endif

#endif


int main(){
int j1;
int j2;
double** data2;
scalar_t__* mean;
double* stddev;
double** symmat;

#pragma scop
for ( int i = 1 ; i <= N; i++){
for ( int j = 1 ; j <= M; j++){
data2 [ i ] [ j ] -= mean [ j ] ;
data2 [ i ] [ j ] /= sqrt (N) * stddev [ j ] ;
}

for ( j1 = 1 ; j1 <= M-1; j1++){
symmat [ j1 ] [ j1 ] = 1.0 ;
for ( j2 = j1+1; j2 <= M; j2++){
symmat [ j1 ] [ j2 ] = 0.0 ;
symmat [ j1 ] [ j2 ]+=(data2 [ i ] [ j1 ] * data2 [ i ] [ j2 ] ) ;
symmat [ j2 ] [ j1 ] = symmat [ j1 ] [ j2 ] ;
}
}
}

#pragma endscop
printf("The value of data2 is %p", data2);
printf("The value of mean is %p", mean);
printf("The value of stddev is %p", stddev);
printf("The value of symmat is %p", symmat);

return 0;
}