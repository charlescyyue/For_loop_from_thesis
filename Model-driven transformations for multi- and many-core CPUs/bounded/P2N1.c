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

#if !defined(NT) && !defined(NY) && !defined(NX)
# ifdef DATASET_XS
# define NT 16
# define NY 16
# define NX 16
#endif

# ifdef DATASET_S
# define NT 64
# define NY 64
# define NX 64
#endif

# ifdef DATASET_M
# define NT 256
# define NY 256
# define NX 256
#endif

# ifdef DATASET_L
# define NT 1024
# define NY 1024
# define NX 1024
#endif

# ifdef DATASET_XL
# define NT 4096
# define NY 4096
# define NX 4096
#endif

# ifdef DATASET_XXL
# define NT 16384
# define NY 16384
# define NX 16384
#endif

# ifdef DATASET_XXXL
# define NT 65536
# define NY 65536
# define NX 65536
#endif

#endif


int main(){
size_t i;
size_t t;
size_t j;
double* data;
double** ex;
double** ey;
double** hz;

#pragma scop
for(t = 0; t < NT; t++){
for (j = 0; j < NY; j++)
 ey [0][j] = data[t];
for (i = 1; i < NX; i++)
for (j = 0; j < NY; j++)
 ey[i][j] = ey[i][j] - 0.5*( hz[i][j]-hz[i -1][j]);
for (i = 0; i < NX; i++)
for (j = 1; j < NY; j++)
 ex[i][j] = ex[i][j] - 0.5*( hz[i][j]-hz[i][j -1]);
for (i = 0; i < NX -1; i++)
for (j = 0; j < NY -1; j++)
 hz[i][j] = hz[i][j] - 0.7 * (ex[i][j+1] - ex[i][j] + ey[i+1][j] - ey[i][j]);
}

#pragma endscop
printf("The value of data is %p", data);
printf("The value of ex is %p", ex);
printf("The value of ey is %p", ey);
printf("The value of hz is %p", hz);

return 0;
}