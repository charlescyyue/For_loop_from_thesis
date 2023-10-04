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
size_t p;
size_t q;
size_t r;
size_t s;
int**** A;
int** C4;
scalar_t__**** T1;

#pragma scop
for (a=0; a<N; a++)
for (q=0; q<N; q++)
for (r=0; r<N; r++)
for (s=0; s<N; s++)
for (p=0; p<N; p++)
T1[a][q ][ r ][ s ] = T1[a][q ][ r ][ s ] + A[p][q][ r ][ s]*C4[p][a ];

#pragma endscop
printf("The value of A is %p", A);
printf("The value of C4 is %p", C4);
printf("The value of T1 is %p", T1);

return 0;
}