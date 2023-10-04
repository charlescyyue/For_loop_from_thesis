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
size_t j;
size_t ubj;
int** A;
int** B;
int* C;
size_t ubj2;

#pragma scop
for (j = ubj - ubj2; j < ubj; ++j) {
A[i-1][j] = B[i-1][j];
B[i][j] = C[i]*A[i-1][j];
}

#pragma endscop
printf("The value of A is %p", A);
printf("The value of B is %p", B);
printf("The value of C is %p", C);

return 0;
}