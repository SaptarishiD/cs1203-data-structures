// Takes randomly generated array of n elements and sorts it in ascending order using selection sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void swap(int *a, int *b);
int * generateArray(int n);
void printArray(int * a, int n);
void printArray1(int *a, int n);
int findIndexOfMax(int *a, int n);
void selectionSort(int *a, int n); 




int main(int argc, char **argv) 
{
	int * a;
	int n = 10;
	nodeAddress list;

	srand(time(NULL));

	a = generateArray(n);
	printArray(a,n);
	selectionSort(a,n);
    printf("Sorted ");
	printArray(a,n);


	return 0;
}



void swap(int * a, int * b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;  
}


int * generateArray(int n) 
{
	int * t = malloc( n * sizeof(int) );
	if(t) 
    {
		for(int i=0; i<n; i++) 
        {
            t[i] = rand()%1000;
        }
	}
	return t;
}


void printArray(int * a, int n) 
{
	printf("Array = ");
	for(int i=0; i<n; i++) 
    {
		printf( i?", %d":"%d", a[i]);
	}
	printf(".\n");
}

void printArray1(int *a, int n) 
{
	for(int i=0; i<n; i++) 
    {
		printf(" %d ", a[i]);
	}
}



int findIndexOfMax(int *a, int n) 
{
	int imax; // this will contain the address of the largest element encountered.
	int i;

	// error case if there are no elements in the list
	if(n<1) {return -1;}

	imax = 0; // I am assuming that a[0] is the max element
	for(i=1; i<n; i++) 
    {
		if( a[i] > a[imax] ) 
        {
			imax = i;
		}
	}

	return imax;
}

void selectionSort(int *a, int n) 
{
	int i, imax, t;

	for(i=n; i>1; i=i-1) 
    {
		imax = findIndexOfMax(a, i);
		t = a[imax]; a[imax] = a[i-1]; a[i-1] = t;
	}
}









