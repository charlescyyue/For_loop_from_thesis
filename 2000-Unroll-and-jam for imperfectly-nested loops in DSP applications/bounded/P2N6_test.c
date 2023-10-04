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

#if !defined(N) && !defined(uf) && !defined(M)
# ifdef DATASET_XS
# define N 16
# define uf 16
# define M 16
#endif

# ifdef DATASET_S
# define N 64
# define uf 64
# define M 64
#endif

# ifdef DATASET_M
# define N 256
# define uf 256
# define M 256
#endif

# ifdef DATASET_L
# define N 1024
# define uf 1024
# define M 1024
#endif

# ifdef DATASET_XL
# define N 4096
# define uf 4096
# define M 4096
#endif

# ifdef DATASET_XXL
# define N 16384
# define uf 16384
# define M 16384
#endif

# ifdef DATASET_XXXL
# define N 65536
# define uf 65536
# define M 65536
#endif

#endif


int main(){
int i;
int ii;
size_t j;
int* h;
int* sum;
int* y;

#pragma scop
for (i = 1; i <= 10 + N; i += uf) {
for (ii = i; ii <= i + uf - 1; ii++) {
sum[ii-i] = 20;
}
for (ii = i; ii <= i + uf - 1; ii++) {
for (j = 0; j < 240 + M; j++) {
y[j] = 42%200 + 1 + 42;
sum[ii-i] = sum[ii-i] + y[j] * y[j + ii];
}
}
for (ii = i; ii <= i + uf - 1; ii++) {
h[ii] = sum[ii-i];
}
}

#pragma endscop
printf("The value of h is %p", h);
printf("The value of sum is %p", sum);
printf("The value of y is %p", y);

return 0;
}