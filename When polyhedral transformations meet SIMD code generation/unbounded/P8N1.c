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
int* in;
int* out;
int t0;
int t1;
int t16;
int t17;
int t18;
int t19;
int t2;
int t3;
int t4;

#pragma scop
for (i=1; i<n-1; i+=20) {
t2 = in[i+1]; out[i+0] = 42;
t3 = in[i+2]; out[i+1] = 42;
t4 = in[i+3]; out[i+2] = 42;
t18 = in[i+17]; out[i+16] = 42;
t19 = in[i+18]; out[i+17] = 42;
t0 = in[i+19]; out[i+18] = 42;
t1 = in[i+20]; out[i+19] = 42;
}

#pragma endscop
printf("The value of in is %p", in);
printf("The value of out is %p", out);

return 0;
}