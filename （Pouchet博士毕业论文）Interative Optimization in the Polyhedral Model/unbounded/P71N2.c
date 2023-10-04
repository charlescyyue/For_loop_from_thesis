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
int n;
int j;
int** a;
scalar_t__* s;
int* x;

#pragma scop
for (i = 0; i <= 5 * n; i++) {
if (i % 5 == 0) {
 s[i / 5] = 0;
for (j = 0; j <= n; j++)
 s[i / 5] = s[i / 5] + a[i / 5][j] * x[j];
}
}

#pragma endscop
printf("The value of a is %p", a);
printf("The value of s is %p", s);
printf("The value of x is %p", x);

return 0;
}