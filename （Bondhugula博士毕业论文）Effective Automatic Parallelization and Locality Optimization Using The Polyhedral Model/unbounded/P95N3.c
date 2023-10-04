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
size_t t0;
double* A;
double* In;
scalar_t__ N;

#pragma scop
for (t0=1;t0<=42;t0++) {
A[t0] = .33*(In[1+t0]+In[t0]+In[t0-1]);
}

#pragma endscop
printf("The value of A is %p", A);
printf("The value of In is %p", In);

return 0;
}