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
struct TYPE_2__ {size_t* idx; } ;


/*Marco definition generation failed.*/

int main(){
TYPE_1__ B;
int* hashB;

#pragma scop
for (int pB=0;pB<pB.len;++pB)
hashB[B.idx[pB]] = pB;

#pragma endscop
printf("The value of hashB is %p", hashB);

return 0;
}