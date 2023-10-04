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
scalar_t__* a2;
scalar_t__* a3;

#pragma scop
for ( i=1; i<n-1; i++) {
a3[ i ] = a2[i-1] + a2[i] + a2[i+1];
}

#pragma endscop
printf("The value of a2 is %p", a2);
printf("The value of a3 is %p", a3);

return 0;
}