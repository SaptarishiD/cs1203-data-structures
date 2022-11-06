#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void heapify(int array[], int size, int nodeindex);
void insertNode(int array[], int size, int newelement);
void printArray(int array[], int size);
void swap(int * a, int * b);

int main()
{

    int myarray[500] = {0,11,22,33,44,55}; // 500 is the maximum size of the array/heap
    int size = 6;
    printArray(myarray, size);
    
	int insertelement = 15;

    insertNode(myarray, size, insertelement);
    printf("Array after insertion: ");
	printArray(myarray, size+1);
}




void swap(int * a, int * b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int size, int nodeindex)
{
	int parent = (nodeindex - 1) / 2;

    /**if current element less than its parent then swap them and
     * call heapify again on the parent index*/

		if (arr[nodeindex] < arr[parent]) 
        {
			swap(&arr[nodeindex], &arr[parent]);
			heapify(arr, size, parent);
		}
	
}

// Function to insert a new node to the Heap
void insertNode(int array[], int size, int newelement)
{
	
	size = size + 1; //increment n in order to increase the apparent size of the array to accomodate the new element
	array[size - 1] = newelement;
	heapify(array, size, size - 1);
}

void printArray(int array[], int size)
{
    printf("Array: ");
	for (int i = 0; i < size; ++i)
		printf(" %i ", array[i]);
	printf("\n");
}