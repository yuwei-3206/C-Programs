/**
	@file
	@author Yuwei Wu <yw829@drexel.edu>
	@date March 5, 2024
	@section DESCRIPTION

	This is a header file for Cube Sum.
 */

#ifndef CUBE_H
#define CUBE_H

/**
   A structure to represent a cube sum.
   Stores three integer values i, j, and k, where i^3 + j^3 = k.
 */
typedef struct {
    int i; /**< The first integer value. */
    int j; /**< The second integer value. */
    int k; /**< The sum of cubes of the two int values (i^3 + j^3). */
} CubeSum;

/**
   Calculate a new cube sum.
   @param i is the first int value
   @param i is the second int value
   @param k is the sum of cubes of the two int values
   @return sum of the cube
 */
CubeSum *newCubeSum(int i, int j, int k);

#endif
