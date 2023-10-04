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

#if !defined(M) && !defined(E) && !defined(F) && !defined(C) && !defined(R) && !defined(S)
# ifdef DATASET_XS
# define M 16
# define E 16
# define F 16
# define C 16
# define R 16
# define S 16
#endif

# ifdef DATASET_S
# define M 64
# define E 64
# define F 64
# define C 64
# define R 64
# define S 64
#endif

# ifdef DATASET_M
# define M 256
# define E 256
# define F 256
# define C 256
# define R 256
# define S 256
#endif

# ifdef DATASET_L
# define M 1024
# define E 1024
# define F 1024
# define C 1024
# define R 1024
# define S 1024
#endif

# ifdef DATASET_XL
# define M 4096
# define E 4096
# define F 4096
# define C 4096
# define R 4096
# define S 4096
#endif

# ifdef DATASET_XXL
# define M 16384
# define E 16384
# define F 16384
# define C 16384
# define R 16384
# define S 16384
#endif

# ifdef DATASET_XXXL
# define M 65536
# define E 65536
# define F 65536
# define C 65536
# define R 65536
# define S 65536
#endif

#endif


int main(){
size_t i;
size_t j;
size_t m;
size_t n;
size_t p;
size_t q;
size_t k;
double**** Filter;
double**** Ifmap;
double**** Ofmap;

#pragma scop
for (j = 0; j < M; j++)
for (k = 0; k < E; k ++)
for (m = 0; m < F; m++) {
 Ofmap [i][j][k][m] = 0.0;
for (n = 0; n < C; n ++)
for (p = 0; p < R; p ++)
for (q = 0; q < S; q ++)
 Ofmap [i][j][k][m] += Filter [j][n][p][q] * Ifmap [i][n][k+p][m+q];
}

#pragma endscop
printf("The value of Filter is %p", Filter);
printf("The value of Ifmap is %p", Ifmap);
printf("The value of Ofmap is %p", Ofmap);

return 0;
}