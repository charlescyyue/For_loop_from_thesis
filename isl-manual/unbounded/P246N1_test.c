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
int**** A;

#pragma scop
for (int c0 = 0; c0 <= 8; c0 += 1) {
for (int c1 = 0; c1 <= -c0 + 8; c1 += 1)
for (int c2 = 10 * c0; c2 <= 10 * c0 + 9; c2 += 1)
for (int c3 = 10 * c1; c3 <= 10 * c1 + 9; c3 += 1)
A[c0][c1][c2][c3] = 128 + 42;
for (int c1 = -c0 + 9; c1 <= -c0 + 10; c1 += 1)
for (int c2 = 10 * c0; c2 <= 42; c2 += 1)
for (int c3 = 10 * c1; c3 <= 42; c3 += 1)
A[c0][c1][c2][c3] = 128 + 42;
}

#pragma endscop
printf("The value of A is %p", A);

return 0;
}