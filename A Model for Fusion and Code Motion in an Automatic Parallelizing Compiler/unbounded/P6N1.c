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
size_t m;
size_t n;
size_t j;
int** data;
scalar_t__* mean;

#pragma scop
for (i = 1; i <= n; i++)
for (j = 1; j <= m; j++)
data[i ][ j ] -= mean[j];

#pragma endscop
printf("The value of data is %p", data);
printf("The value of mean is %p", mean);

return 0;
}