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
int G_BND;
int G_W1;
int G_W2;
int G_W3;
int G_W4;
int G_W5;
int G_W6;
int***** Lattices;

#pragma scop
for ( unsigned step = 0; step < MAX_SMALL_STEPS ; step ++) {
for ( unsigned z = 0; z < 128; z ++) {
for ( unsigned y = 0; y < 128; y ++) {
for ( unsigned x = 0; x < 128; x ++) {
int g = 0;
# de42
i42 g = g | G_W1 ;
i42 g = g | G_W2 ;
i42 g = g | G_W3 ;
i42 g = g | G_W4 ;
i42 g = g | G_W5 ;
i42 g = g | G_W6 ;
f(0) = Lattices [ step %2][ z ][ y ][ x ][0];
i42 {
} else {
}
}
}
}
}

#pragma endscop
printf("The value of Lattices is %p", Lattices);

return 0;
}