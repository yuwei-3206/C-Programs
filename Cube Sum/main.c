/**
    @mainpage CubeSum
    @section Description

    This program takes a maximum int value from the user and generates all possible cube sums from 0 to that value.
    Cube sums are computed as the sum of cubes of two integers (i^3 + j^3 = k).
 */

/**
	@file
	@author Yuwei Wu <yw829@drexel.edu>
	@date March 5, 2024
	@section DESCRIPTION

    The file contains a main program that prompts the user for a maximum int value, and a function that generates all possible cube sums.
 */

#include <stdio.h>
#include "cube.h"
#include "heap.h"

/**
    Generates and prints cube sums up to a given maximum value.
    @param n The maximum value for cube sums
 */
void generateAndPrintCubeSums(int n);

int main() {
    int n;
    printf("Cube Sum Program.\n");
    printf("Computes Cube Sums from 0 ... N\n");
    printf("Enter max value of N:\n");
    scanf("%d", &n);

    generateAndPrintCubeSums(n);

    return 0;
}

void generateAndPrintCubeSums(int n) {
    Heap *myHeap = newHeap();

    // Generate cube sums and insert them into the heap
    for (int j = 0; j <= n; j++) {
        for (int i = 0; i <= n; i++) {
            insert(myHeap, newCubeSum(i, j, i * i * i + j * j * j));
        }
    }

    while (!isEmpty(myHeap)) {
        // Get the minimum cube sum from the heap
        CubeSum *minSum = getMin(myHeap);
        printf("%d^3 + %d^3 = %d\n", minSum->i, minSum->j, minSum->k);

        // Remove the minimum cube sum from the heap
        removeMin(myHeap);
    }

    // Free memory
    deleteHeap(myHeap);
}
