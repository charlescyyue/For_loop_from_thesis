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


/*Marco definition generation failed.*/

int main(){
int c1;
int n;
scalar_t__* a0;
scalar_t__* a1;
scalar_t__* a2;
scalar_t__* a3;
scalar_t__* a4;
scalar_t__* a5;

#pragma scop
for (c1=9;c1<=n-2;c1++) {
a1[c1]=a0[1+c1]+a0[c1]+a0[c1-1];
a2[c1-1]=a1[1+c1-1]+a1[c1-1]+a1[c1-1 -1];
a3[c1-2]=a2[1+c1-2]+a2[c1-2]+a2[c1-2 -1];
a4[c1-3]=a3[1+c1-3]+a3[c1-3]+a3[c1-3 -1];
a5[c1-4]=a4[1+c1-4]+a4[c1-4]+a4[c1-4 -1];
}

#pragma endscop
printf("The value of a0 is %p", a0);
printf("The value of a1 is %p", a1);
printf("The value of a2 is %p", a2);
printf("The value of a3 is %p", a3);
printf("The value of a4 is %p", a4);
printf("The value of a5 is %p", a5);

return 0;
}