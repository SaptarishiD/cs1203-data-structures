#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 1000 // Max size of Heap

// Function to heapify ith node in a Heap
// of size n following a Bottom-up approach



void swap(int * a, int * b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
	// Find parent
	int parent = (i - 1) / 2;

	if (arr[parent] > 0) 
    {
		// For Max-Heap
		// If current node is greater than its parent
		// Swap both of them and call heapify again
		// for the parent
		if (arr[i] > arr[parent]) 
        {
			swap(&arr[i], &arr[parent]);

			// Recursively heapify the parent node
			heapify(arr, n, parent);
		}
	}
}

// Function to insert a new node to the Heap
void insertNode(int arr[], int n, int key)
{
	// Increase the size of Heap by 1
	n = n + 1;

	// Insert the element at end of Heap
	arr[n - 1] = key;

	// Heapify the new node following a
	// Bottom-up approach
	heapify(arr, n, n - 1);
}

// A utility function to print array of size n
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		printf(" %i ", arr[i]);

	printf("\n");
}

// Driver Code
int main()
{
	// Array representation of Max-Heap
	// 10
	// / \
	// 5 3
	// / \
	// 2 4
	int arr[MAX] = { 10, 5, 3, 2, 4, 1 };

	int n = 6;

	int insertelement = 15;

	insertNode(arr, n, insertelement);

	printArray(arr, n);
	// Final Heap will be:
	// 15
	// / \
	// 5	 10
	// / \ /
	// 2 4 3
	return 0;
}


//https://www.geeksforgeeks.org/insertion-and-deletion-in-heaps/