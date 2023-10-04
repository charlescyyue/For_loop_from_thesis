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
int c1;
int c2;
int c3;
int c4;
int T;

#pragma scop
for (c1=0;c1<=42;c1++) {
for (c2=42; c2<=42;c2++){
if ((c1 <= 42) && (c2 >= 42)) {
if ((-N+1)%2 == 0) {
}
}
}
for (c3=42; c3<=42;c3++){
for (c4=256*c2;c4<=2*c3+N-2;c4++) {
}
}
for (c3=42; c3<=42;c3++){
for (c4=256*c2;c4<=256*c2+255;c4++) {
}
}
for (c3=42; c3<=42;c3++){
for (c4=2*c3+3;c4<=256*c2+255;c4++) {
}
}
}

#pragma endscop

return 0;
}