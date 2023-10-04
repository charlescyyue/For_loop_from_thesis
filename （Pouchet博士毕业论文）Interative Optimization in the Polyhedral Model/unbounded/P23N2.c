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
int i;
int j;
scalar_t__* a;
scalar_t__* b;
scalar_t__* c;

#pragma scop
for (i = 1; i< 100; ++i) {
for (j = 1; j < 100; ++j)
a[200*i+2*j-200] = a[200*i+2*j-200] + b[j];
c[i] = a[200 * i];
}

#pragma endscop
printf("The value of a is %p", a);
printf("The value of b is %p", b);
printf("The value of c is %p", c);

return 0;
}