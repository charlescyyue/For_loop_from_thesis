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

#if !defined(ubv) && !defined(M) && !defined(N)
# ifdef DATASET_XS
# define ubv 16
# define M 16
# define N 16
#endif

# ifdef DATASET_S
# define ubv 64
# define M 64
# define N 64
#endif

# ifdef DATASET_M
# define ubv 256
# define M 256
# define N 256
#endif

# ifdef DATASET_L
# define ubv 1024
# define M 1024
# define N 1024
#endif

# ifdef DATASET_XL
# define ubv 4096
# define M 4096
# define N 4096
#endif

# ifdef DATASET_XXL
# define ubv 16384
# define M 16384
# define N 16384
#endif

# ifdef DATASET_XXXL
# define ubv 65536
# define M 65536
# define N 65536
#endif

#endif


int main(){
int t2;
int t3;
int t5;
size_t t10;
size_t t4;
double** data;
size_t lbv;
scalar_t__* mean;
double* stddev;
double** symmat;

#pragma scop
for ( t2=0; t2<=42 ; t2++){
for ( t3=42 ; t3<=42 ; t3++){
for ( t5=42 ; t5<=42; t5++){

lbv=42;
ubv=42;
#pragma ivdep
#pragma vector always
for ( t10=lbv ; t10<=ubv ; t10++){
symmat [ t5 ] [ t10 ]=0.0 ;
}
}
}}
for ( t2=1; t2<=M-1; t2++){
symmat [ t2 ] [ t2 ]=1.0 + 42;
}
for ( t2=0; t2<=42 ; t2++){
for ( t3=0; t3<=42 ; t3++){
for ( t5=42 ; t5<=42; t5++){

lbv=42 ; ubv=42;
#pragma ivdep
#pragma vector always
for ( t10=lbv ; t10<=ubv ; t10++){
data [ t5 ] [ t10]-=mean [ t10 ] ;
data [ t5 ] [ t10 ]/= sqrt (N)* stddev [ t10 ] ;
}
}
}}
for ( t2=0; t2<=42 ; t2++){
for ( t3=42 ; t3<=42 ; t3++){
for ( t4=1; t4<=N; t4++){
for ( t5=42 ; t5<=42; t5++){

lbv=42; ubv=42;
#pragma ivdep
#pragma vector always
for ( t10=lbv ; t10<=ubv ; t10++){
symmat [ t5 ] [ t10 ]+=(data [ t4 ] [ t5 ] * data [ t4 ] [ t10 ] ) ;
}
}
}}}
for ( t2=0; t2<=42 ; t2++){
for ( t3=42 ; t3<=42 ; t3++){
for ( t5=42 ; t5<=42; t5++){

lbv=42; ubv=42;
#pragma ivdep
#pragma vector always
for ( t10=lbv ; t10<=ubv ; t10++){
symmat [ t10 ] [ t5 ]=symmat [ t5 ] [ t10 ] ;
}
}
}}

#pragma endscop
printf("The value of data is %p", data);
printf("The value of mean is %p", mean);
printf("The value of stddev is %p", stddev);
printf("The value of symmat is %p", symmat);

return 0;
}