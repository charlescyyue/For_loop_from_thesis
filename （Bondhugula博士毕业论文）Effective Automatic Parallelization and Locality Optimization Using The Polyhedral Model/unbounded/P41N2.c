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
size_t n;
size_t j;
size_t k;
int** C;
scalar_t__** D;
int** E;

#pragma scop
for ( i=0; i<n; i++) {
for ( j=0; j<n; j++) {
for (k=0; k<n; k++) {
 D[i ][ j ] = D[i][j ] + E[i][k] * C[k][j ];
}
}
}

#pragma endscop
printf("The value of C is %p", C);
printf("The value of D is %p", D);
printf("The value of E is %p", E);

return 0;
}