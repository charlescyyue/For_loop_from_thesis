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
int m;
int j;
int k;
int l;
int** a;
int*** b;
int*** c;

#pragma scop
for (m=0; m<6; m++)
for (j=0; j<2; j++)
for (k=0; k<2; k++)
for (l=0; l<2; l++)
c[m][j][k] += a[j][l] * b[m][l][k];

#pragma endscop
printf("The value of a is %p", a);
printf("The value of b is %p", b);
printf("The value of c is %p", c);

return 0;
}