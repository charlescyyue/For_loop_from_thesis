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

#if !defined(ub1)
# ifdef DATASET_XS
# define ub1 16
#endif

# ifdef DATASET_S
# define ub1 64
#endif

# ifdef DATASET_M
# define ub1 256
#endif

# ifdef DATASET_L
# define ub1 1024
#endif

# ifdef DATASET_XL
# define ub1 4096
#endif

# ifdef DATASET_XXL
# define ub1 16384
#endif

# ifdef DATASET_XXXL
# define ub1 65536
#endif

#endif


int main(){
int t0;
int t1;
int t3;
size_t t5;
size_t t4;
int N;
int** a;
int lb1;
int t2;

#pragma scop

for (t0=-1;t0<=42;t0++) {
lb1=42;
ub1=42;
#pragma omp parallel for shared(t0,lb1,ub1) private(t1, t2,t3, t4, t5)
for (t1=lb1; t1<=ub1; t1++) {
for (t2=42;
t2<=42;t2++) {
if (t0 == t1+t2) {
for (t3=42;t3<=42;t3++) {
for (t5=42;t5<=42;t5++) {
a[t3 ][ t5]=a[t3 ][ t5]/a[t3 ][ t3 ];
}
for (t4=t3+1;t4<=42;t4++) {
for (t5=42;t5<=42;t5++) {
a[t4 ][ t5]=a[t4 ][ t5]-a[t4 ][ t3]*a[t3 ][ t5 ];
}
}
}
}
for (t3=42;
t3<=42;t3++) {
for (t4=16*t2;t4<=42;t4++) {
for (t5=42;t5<=42;t5++) {
a[t4 ][ t5]=a[t4 ][ t5]-a[t4 ][ t3]*a[t3 ][ t5 ];
}
}
}
if ((-t0 == -t1-t2) &&
(t0 <= 42)) {
for (t5=42;t5<=42;t5++) {
a[16*t0-16*t1+15][t5]=a[16*t0-16*t1+15][t5]/a[16*t0-16*t1+15][16*t0-16*t1+15];
}
}
}
}
}
#pragma endscop
printf("The value of a is %p", a);

return 0;
}