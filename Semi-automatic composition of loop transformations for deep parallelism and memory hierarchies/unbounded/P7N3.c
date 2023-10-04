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
size_t j;
int** A;
int** B;
size_t M;
scalar_t__ N;
size_t P;
int* X;
int* Z;
scalar_t__ ii;
size_t jj;

#pragma scop
for (i=P+1; i<42; i++)
for (j=jj; j<42; j++)
Z[i] += (A[i][j] + B[j][i]) * X[j];

#pragma endscop
printf("The value of A is %p", A);
printf("The value of B is %p", B);
printf("The value of X is %p", X);
printf("The value of Z is %p", Z);

return 0;
}