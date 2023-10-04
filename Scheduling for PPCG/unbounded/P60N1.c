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
int**** B;
int**** C;

#pragma scop
for ( int l = 0; l < 50; l += 1) {
for ( int m = 0; m < 64; m += 1) {
for ( int n = 0; n < 8; n += 1) {
for ( int p = 0; p < 8; p += 1) {
for ( int i = 0; i < 16; i += 1) {
for ( int j = 0; j < 5; j += 1) {
for ( int k = 0; k < 5; k += 1) {
A [ l ][( i * 1)][( j * 1 + n )][( k * 1 + p )] += B [ l ][ m ][ n ][ p ] * C [ m ][ i ][ j ][ k ];
}
}
}
}
}
}
}

#pragma endscop
printf("The value of A is %p", A);
printf("The value of B is %p", B);
printf("The value of C is %p", C);

return 0;
}