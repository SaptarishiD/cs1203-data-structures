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

void heapify(int arr[], int n, int nodeindex)
{
	// Find parent
	int parent = (nodeindex - 1) / 2;

	if (arr[parent] > 0) 
    {
		// For min-Heap
		// If current node is lesser than its parent
		// Swap both of them and call heapify again
		// for the parent


		if (arr[nodeindex] < arr[parent]) 
        {
			swap(&arr[nodeindex], &arr[parent]);

			// Recursively heapify the parent node
			heapify(arr, n, parent);
		}
	}
}

// Function to insert a new node to the Heap
void insertNode(int arr[], int n, int newelement)
{
	// Increase the size of Heap by 1
	n = n + 1;

	// Insert the element at end of Heap
	arr[n - 1] = newelement;

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

	int arr[MAX] = { 10, 5, 3, 2, 4 };

    int arr1[MAX] = {0,11,22,33,44,55};

	// int sizeofmaxarray = 5;

	int insertelement = 15;

    // int sizeofminarray = 6;

	// insertNode(arr, sizeofmaxarray, insertelement);

	// printArray(arr, sizeofmaxarray);

    int sizeofminarray = 6;

    insertNode(arr1, sizeofminarray, insertelement);

	printArray(arr1, sizeofminarray+1);


	return 0;
}


//https://www.geeksforgeeks.org/insertion-and-deletion-in-heaps/