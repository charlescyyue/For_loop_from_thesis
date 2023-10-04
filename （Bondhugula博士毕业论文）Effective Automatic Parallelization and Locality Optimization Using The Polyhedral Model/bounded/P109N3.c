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

#if !defined(N)
# ifdef DATASET_XS
# define N 16
#endif

# ifdef DATASET_S
# define N 64
#endif

# ifdef DATASET_M
# define N 256
#endif

# ifdef DATASET_L
# define N 1024
#endif

# ifdef DATASET_XL
# define N 4096
#endif

# ifdef DATASET_XXL
# define N 16384
#endif

# ifdef DATASET_XXXL
# define N 65536
#endif

#endif


int main(){
size_t a;
size_t b;
size_t c;
size_t s;
size_t r;
int** C2;
int**** T2;
scalar_t__**** T3;

#pragma scop
for (a=0; a<N; a++)
for (b=0; b<N; b++)
for (c=0; c<N; c++)
for (s=0; s<N; s++)
for (r=0; r<N; r++)
T3[a][b ][ c ][ s ] = T3[a][b][ c ][ s ] + T2[a][b ][ r ][ s ]*C2[r ][ c ];

#pragma endscop
printf("The value of C2 is %p", C2);
printf("The value of T2 is %p", T2);
printf("The value of T3 is %p", T3);

return 0;
}