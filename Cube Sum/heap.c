/**
	@file
	@author Yuwei Wu <yw829@drexel.edu>
	@date March 5, 2024
	@section DESCRIPTION

	This is a c file that store implementations of heap.h.
 */

#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
     Create a new heap with starting size 10.
     @return the heap that was created.
 */
Heap *newHeap() {
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->capacity = 10;
    heap->size = 0;
    heap->array = (CubeSum **)malloc(heap->capacity * sizeof(CubeSum *));
    return heap;
}

/**
    Delete the heap. Free all memory used.
    @param myHeap is the heap to delete
 */
void deleteHeap(Heap *myHeap) {
    if (myHeap) {
        free(myHeap->array);
        free(myHeap);
    }
}

/**
     Determine if the heap is empty.
     @param myHeap is the heap to check
     @return true if the heap is empty and false otherwise
 */
bool isEmpty(Heap *myHeap) {
    return myHeap->size == 0;
}

/**
    Compares two CubeSum pointers based on their k, i, and j values.
    @param a is a pointer to the first CubeSum pointer.
    @param b is a pointer to the second CubeSum pointer.
    @return Negative value if the first cube sum should appear before the second one
            positive value if the second cube sum should appear before the first one
            zero if they are equal
 */
int compareCubeSums(const void *a, const void *b) {
    CubeSum *sum1 = *(CubeSum **)a;
    CubeSum *sum2 = *(CubeSum **)b;

    // Compare k values
    if (sum1->k != sum2->k) {
        return sum1->k - sum2->k;
    }

    // If k values are equal, compare i values
    if (sum1->i != sum2->i) {
        return sum1->i - sum2->i;
    }

    // If i values are equal, compare j values
    return sum1->j - sum2->j;
}

/**
     Insert a new sum into the heap.
     @param myHeap is the heap to insert into
     @param sum is a pointer to the sum to insert
 */
void insert(Heap *myHeap, CubeSum *sum) {
    if (myHeap->size == myHeap->capacity) {
        myHeap->capacity *= 2;
        myHeap->array = (CubeSum **)realloc(myHeap->array, myHeap->capacity * sizeof(CubeSum *));
    }
    myHeap->array[myHeap->size++] = sum;

    qsort(myHeap->array, myHeap->size, sizeof(CubeSum *), compareCubeSums);
}

/**
     Remove the minimum from the heap.
     @param myHeap is the heap to remove from
 */
void removeMin(Heap *myHeap) {
    if (isEmpty(myHeap)) return;

    // Move the last element to the root
    myHeap->array[0] = myHeap->array[--myHeap->size];

    qsort(myHeap->array, myHeap->size, sizeof(CubeSum *), compareCubeSums);
}

/**
     Get the pointer to the smallest CubeSum.
     @param myHeap is the heap to get the min of
     @return a pointer to the smallest CubeSum
 */
CubeSum *getMin(Heap *myHeap) {
    if (isEmpty(myHeap)) return NULL;
    return myHeap->array[0];
}
