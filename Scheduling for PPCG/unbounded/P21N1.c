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
scalar_t__* A;
scalar_t__* B;

#pragma scop
for ( int i = 0; i < n ; i ++)
if ( B [ i ] > 0)
A [ i ] = B [ i ];

#pragma endscop
printf("The value of A is %p", A);
printf("The value of B is %p", B);

return 0;
}