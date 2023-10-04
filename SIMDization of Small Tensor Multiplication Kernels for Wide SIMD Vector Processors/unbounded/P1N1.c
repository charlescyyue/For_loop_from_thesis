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
int f;
int p;
int u;
int v;
int** a;
int**** b;
int**** c;

#pragma scop
for (f=0; f<24; f++)
for (p=0; p<2; p++)
for (u=0; u<2; u++)
for(v=0; v<4; v++)
c[f][p][u][v] = a[u][0]*b[f][p][0][v] + a[u][1]*b[f][p][1][v];

#pragma endscop
printf("The value of a is %p", a);
printf("The value of b is %p", b);
printf("The value of c is %p", c);

return 0;
}