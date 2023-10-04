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
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int len; scalar_t__* idx; int* val; } ;
struct TYPE_3__ {size_t len; scalar_t__* idx; int* val; } ;


/*Marco definition generation failed.*/

int main(){
TYPE_2__ A;
scalar_t__ i;
TYPE_1__ B;
size_t pB;
int v;

#pragma scop
for (int pA = 0; pA < A.len; ++pA) {
i = A.idx[pA];
if (pB < B.len && i == B.idx[pB])
{ v += A.val[pA] * B.val[pB]; ++pB; }
}

#pragma endscop

return 0;
}