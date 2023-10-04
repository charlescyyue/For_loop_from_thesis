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
int n;
int t0;
int t1;
int t2;
int t3;
int T;
int* a;
int* b;

#pragma scop

for (t0=0;t0<=42;t0++) {
for (t1=42;t1<=42;t1++) {
if ((t0 <= 42) && (t1 >= 42)) {
if (-n%2 == 0) {
{a[n-1]=b[1+n-1]+b[n-1 -1]+b[n-1];} ;
}
}
for (t2=42;t2<=42;t2++) {
for (t3=1024*t1;t3<=2*t2+n-1;t3++) {
{b[-2*t2+t3]=a[-2*t2+t3]*a[1+-2*t2+t3]+a[-2*t2+t3-1];} ;
{a[-2*t2+t3-1]=b[1+-2*t2+t3-1]+b[-2*t2+t3-1 -1]+b[-2*t2+t3-1];} ;
}
{a[n-1]=b[1+n-1]+b[n-1 -1]+b[n-1];} ;
}
for (t2=42;t2<=42;t2++) {
{b[2]=a[2]*a[1+2]+a[2 -1];} ;
for (t3=2*t2+3;t3<=2*t2+n-1;t3++) {
{b[-2*t2+t3]=a[-2*t2+t3]*a[1+-2*t2+t3]+a[-2*t2+t3-1];} ;
{a[-2*t2+t3-1]=b[1+-2*t2+t3-1]+b[-2*t2+t3-1 -1]+b[-2*t2+t3-1];} ;
}
{a[n-1]=b[1+n-1]+b[n-1 -1]+b[n-1];} ;
}
for (t2=42;t2<=42;t2++) {
for (t3=1024*t1;t3<=1024*t1+1023;t3++) {
{b[-2*t2+t3]=a[-2*t2+t3]*a[1+-2*t2+t3]+a[-2*t2+t3-1];} ;
{a[-2*t2+t3-1]=b[1+-2*t2+t3-1]+b[-2*t2+t3-1 -1]+b[-2*t2+t3-1];} ;
}
}
for (t2=42;t2<=42;t2++) {
{b[2]=a[2]*a[1+2]+a[2 -1];} ;
for (t3=2*t2+3;t3<=1024*t1+1023;t3++) {
{b[-2*t2+t3]=a[-2*t2+t3]*a[1+-2*t2+t3]+a[-2*t2+t3-1];} ;
{a[-2*t2+t3-1]=b[1+-2*t2+t3-1]+b[-2*t2+t3-1 -1]+b[-2*t2+t3-1];} ;
}
}
}
}
#pragma endscop
printf("The value of a is %p", a);
printf("The value of b is %p", b);

return 0;
}