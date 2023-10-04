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
scalar_t__* a1;
scalar_t__* a2;

#pragma scop
for ( i=1; i<n-1; i++) {
a2[ i ] = a1[i-1] + a1[i] + a1[i+1];
}

#pragma endscop
printf("The value of a1 is %p", a1);
printf("The value of a2 is %p", a2);

return 0;
}