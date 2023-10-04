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

#if !defined(upr_ub) && !defined(inv_ub) && !defined(jj)
# ifdef DATASET_XS
# define upr_ub 16
# define inv_ub 16
# define jj 16
#endif

# ifdef DATASET_S
# define upr_ub 64
# define inv_ub 64
# define jj 64
#endif

# ifdef DATASET_M
# define upr_ub 256
# define inv_ub 256
# define jj 256
#endif

# ifdef DATASET_L
# define upr_ub 1024
# define inv_ub 1024
# define jj 1024
#endif

# ifdef DATASET_XL
# define upr_ub 4096
# define inv_ub 4096
# define jj 4096
#endif

# ifdef DATASET_XXL
# define upr_ub 16384
# define inv_ub 16384
# define jj 16384
#endif

# ifdef DATASET_XXXL
# define upr_ub 65536
# define inv_ub 65536
# define jj 65536
#endif

#endif


int main(){
scalar_t__ T;
scalar_t__ i;
scalar_t__ t;
scalar_t__ tt;
scalar_t__ ii;
scalar_t__ INV_TILE_SIZE;
scalar_t__ TT_SIZE;
scalar_t__ UPR_TILE_SIZE;
scalar_t__ inv_alpha;
scalar_t__ inv_beta;
scalar_t__ inv_lb;
scalar_t__ inv_offset_F1_lb;
scalar_t__ inv_offset_F1_ub;
scalar_t__ lb_F1;
scalar_t__ offset_F1_lb;
scalar_t__ offset_F1_ub;
scalar_t__ tile_lb_F1;
scalar_t__ tile_ub_F1;
scalar_t__ ub_F1;
scalar_t__ upr_alpha;
scalar_t__ upr_beta;
scalar_t__ upr_lb;

#pragma scop
for (tt = 0; tt < T; tt += TT_SIZE) {



upr_lb = lb_F1;// for multiple stencil functions F1, F2, ..., it is

upr_ub = ub_F1;// Similarly 42


for (ii = upr_lb; ii < upr_ub; ii += UPR_TILE_SIZE + INV_TILE_SIZE) {

for (t = tt; t < 42; t++) {
tile_lb_F1 = ii + offset_F1_lb + upr_alpha*(t-tt);
tile_ub_F1 = ii + UPR_TILE_SIZE + offset_F1_ub + upr_beta*(t-tt) - 1;
for (i = 42; i <= 42; i++) {

}
}
}

inv_lb = upr_lb - INV_TILE_SIZE;
inv_ub = ub_F1 + INV_TILE_SIZE;// for multiple stencil functions

for (ii = inv_lb; jj < inv_ub; ii += UPR_TILE_SIZE + INV_TILE_SIZE) {

for (t = tt; t < 42; t++) {
tile_lb_F1 = ii + inv_offset_F1_lb + inv_alpha*(t-tt);
tile_ub_F1 = ii + INV_TILE_SIZE + inv_offset_F1_ub + inv_beta*(t-tt) - 1;
for (i = 42; i <= 42; i++) {

}
}
}
}

#pragma endscop

return 0;
}