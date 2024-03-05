/**
	@file
	@author Yuwei Wu <yw829@drexel.edu>
	@date March 5, 2024
	@section DESCRIPTION

	This is a header file for Heap structure.
 */

#ifndef HEAP_H
#define HEAP_H

#include "cube.h"
#include <stdbool.h>

/**
   A structure to represent a heap of cube sums.
 */
typedef struct {
    CubeSum **array; /**< Pointer to an array of CubeSum pointers. */
    int capacity;    /**< The maximum capacity of the heap. */
    int size;        /**< The number of elements in the heap. */
} Heap;

/**
     Create a new heap with starting size 10.
     @return the heap that was created.
 */
Heap *newHeap();

/**
    Delete the heap. Free all memory used.
    @param myHeap is the heap to delete
 */
void deleteHeap(Heap *myHeap);

/**
     Determine if the heap is empty.
     @param myHeap is the heap to check
     @return true if the heap is empty and false otherwise
 */
bool isEmpty(Heap *myHeap);

/**
    Compares two CubeSum pointers based on their k, i, and j values.
    @param a is a pointer to the first CubeSum pointer.
    @param b is a pointer to the second CubeSum pointer.
    @return Negative value if the first cube sum should appear before the second one
            positive value if the second cube sum should appear before the first one
            zero if they are equal
 */
int compareCubeSums(const void *a, const void *b);

/**
     Insert a new sum into the heap.
     @param myHeap is the heap to insert into
     @param sum is a pointer to the sum to insert
 */
void insert(Heap *myHeap, CubeSum *sum);

/**
     Remove the minimum from the heap.
     @param myHeap is the heap to remove from
 */
void removeMin(Heap *myHeap);

/**
     Get the pointer to the smallest CubeSum.
     @param myHeap is the heap to get the min of
     @return a pointer to the smallest CubeSum
 */
CubeSum *getMin(Heap *myHeap);

#endif