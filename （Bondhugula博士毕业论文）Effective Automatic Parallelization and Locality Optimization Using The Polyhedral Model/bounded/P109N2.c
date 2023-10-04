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
size_t q;
size_t b;
size_t r;
size_t s;
int** C3;
int**** T1;
scalar_t__**** T2;

#pragma scop
for (a=0; a<N; a++)
for (b=0; b<N; b++)
for (r=0; r<N; r++)
for (s=0; s<N; s++)
for (q=0; q<N; q++)
T2[a][b ][ r ][ s ] = T2[a][b][ r ][ s ] + T1[a][q ][ r ][ s ]*C3[q][b ];

#pragma endscop
printf("The value of C3 is %p", C3);
printf("The value of T1 is %p", T1);
printf("The value of T2 is %p", T2);

return 0;
}