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
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int len; int /*<<< orphan*/ * idx; } ;


/*Marco definition generation failed.*/

int main(){
TYPE_1__ A;
int i;

#pragma scop
for (int pA = 0; pA < A.len; ++pA)
i = A.idx[pA];// i-loop degenerates into assignment

#pragma endscop

return 0;
}