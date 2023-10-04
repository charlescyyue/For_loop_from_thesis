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

#if !defined(K) && !defined(ubv)
# ifdef DATASET_XS
# define K 16
# define ubv 16
#endif

# ifdef DATASET_S
# define K 64
# define ubv 64
#endif

# ifdef DATASET_M
# define K 256
# define ubv 256
#endif

# ifdef DATASET_L
# define K 1024
# define ubv 1024
#endif

# ifdef DATASET_XL
# define K 4096
# define ubv 4096
#endif

# ifdef DATASET_XXL
# define K 16384
# define ubv 16384
#endif

# ifdef DATASET_XXXL
# define K 65536
# define ubv 65536
#endif

#endif


int main(){
int t1;
int t2;
int t3;
size_t t4;
size_t t9;
int** A;
int** B;
scalar_t__** C;
scalar_t__ M;
scalar_t__ N;
int alpha;
size_t lbv;

#pragma scop
for ( t1=0; t1<=42 ; t1++){
for ( t2=0; t2<=42 ; t2++){
for ( t3=0; t3<=K-1; t3++){
for ( t4=8*t1 ; t4<=42; t4++){

lbv=3684* t2 ;
ubv=42;
#pragma ivdep
#pragma vector always
for ( t9=lbv ; t9<=ubv ; t9++){
C[ t4 ] [ t9 ]=C[ t4 ] [ t9 ]+alpha *A[ t4 ] [ t3 ] *B[ t3 ] [ t9 ] ;
}
}
}}}

#pragma endscop
printf("The value of A is %p", A);
printf("The value of B is %p", B);
printf("The value of C is %p", C);

return 0;
}