/**
	@file
	@author Yuwei Wu <yw829@drexel.edu>
	@date March 5, 2024
	@section DESCRIPTION

	This is a c file that store implementations of cube.h.
 */

#include "cube.h"
#include <stdlib.h>

/**
   Calculate a new cube sum.
   @param i is the first int value
   @param i is the second int value
   @param k is the sum of cubes of the two int values
   @return sum of the cube
 */
CubeSum *newCubeSum(int i, int j, int k) {
    CubeSum *sum = (CubeSum *)malloc(sizeof(CubeSum));
    if (sum != NULL) {
        sum->i = i;
        sum->j = j;
        sum->k = k;
    }
    return sum;
}
