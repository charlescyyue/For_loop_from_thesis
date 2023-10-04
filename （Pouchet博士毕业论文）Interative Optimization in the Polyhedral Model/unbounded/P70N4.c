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
size_t i;
int j1;
int m;
size_t n;
int j2;
double** data;
double** symmat;

#pragma scop
for (j1 = 1; j1 <= m-1; j1++) {
symmat[j1][j1] = 1.0;
for (j2 = j1+1; j2 <= m; j2++) {
symmat[j1][j2] = 0.0;
for (i = 1; i <= n; i++)
symmat[j1][j2] += (data[i][j1] * data[i][j2]);
symmat[j2][j1] = symmat[j1][j2];
}
}

#pragma endscop
printf("The value of data is %p", data);
printf("The value of symmat is %p", symmat);

return 0;
}