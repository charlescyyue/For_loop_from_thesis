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
int k;
int j;
int jj;
int** A;
int** B;
int** C;

#pragma scop
for (k=0; k < 32; k++)
for (j=0; j < 32; j+=4)
for (i=0; i < 32; i++)
for (jj=j; jj < j + 4; j++)
C[i][jj] += A[k][i] * B[jj][k];

#pragma endscop
printf("The value of A is %p", A);
printf("The value of B is %p", B);
printf("The value of C is %p", C);

return 0;
}