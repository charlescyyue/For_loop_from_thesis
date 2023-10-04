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

#if !defined(V) && !defined(O)
# ifdef DATASET_XS
# define V 16
# define O 16
#endif

# ifdef DATASET_S
# define V 64
# define O 64
#endif

# ifdef DATASET_M
# define V 256
# define O 256
#endif

# ifdef DATASET_L
# define V 1024
# define O 1024
#endif

# ifdef DATASET_XL
# define V 4096
# define O 4096
#endif

# ifdef DATASET_XXL
# define V 16384
# define O 16384
#endif

# ifdef DATASET_XXXL
# define V 65536
# define O 65536
#endif

#endif


int main(){
int c1;
int c2;
int c3;
int c4;
int c5;
int c6;
int c8;
int c9;
int**** O1;
int**** O2;
int**** O3;
int** T1;
int**** T2;
int X;
int Y;
scalar_t__ e1;
scalar_t__ e2;

#pragma scop
for (c1=0; c1<=V-1; c1++) {
for (c2=0; c2<=V-1; c2++) {
for (c3=0; c3<=V-1; c3++) {
for (c4=0; c4<=O-1; c4++) {
for (c5=0; c5<=O-1; c5++) {
for (c6=0; c6<=O-1; c6++) {
Y = T1[c3][c6]*O3[c1][c2 ][ c4 ][ c5 ];
for (c8=0; c8<=V-1; c8++) {
for (c9=0; c9<=O-1; c9++) {
X = X + T2[c3][c8][c4][c5]*O2[c1][c2 ][ c8 ][ c6] + T2[c1][c2 ][ c6 ][ c9]*O1[c3][c9 ][ c4 ][ c5 ];
}
}
e1 = e1 + X*X;
e2 = e2 + X*Y;
}
}
}
}
}
}

#pragma endscop
printf("The value of O1 is %p", O1);
printf("The value of O2 is %p", O2);
printf("The value of O3 is %p", O3);
printf("The value of T1 is %p", T1);
printf("The value of T2 is %p", T2);

return 0;
}