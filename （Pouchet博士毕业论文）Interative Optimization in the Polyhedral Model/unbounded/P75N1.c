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
scalar_t__ i;
scalar_t__ m;
scalar_t__ n;
scalar_t__ j;
void** a;
void** b;
void** c;

#pragma scop
for (i = 0; i < n; ++i)
for (j = 0; j < n; ++j) {
 b[j] = a[j];
 c[j] = a[j + m];
}

#pragma endscop
printf("The value of a is %p", a);
printf("The value of b is %p", b);
printf("The value of c is %p", c);

return 0;
}