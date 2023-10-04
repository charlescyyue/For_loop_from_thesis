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
size_t a;
size_t i;
size_t b;
size_t c;
size_t j;
size_t k;
int**** O3;
int** T1;
int****** Y;

#pragma scop
for (a=0;a<V;a++)
for (b=0;b<V;b++)
for (c=0;c<V;c++)
for ( i=0;i<O;i++)
for ( j=0;j<O;j++)
for (k=0;k<O;k++)
Y[a][b ][ c ][ i ][ j ][ k] = T1[c][k]*O3[a][b ][ i ][ j ];

#pragma endscop
printf("The value of O3 is %p", O3);
printf("The value of T1 is %p", T1);
printf("The value of Y is %p", Y);

return 0;
}