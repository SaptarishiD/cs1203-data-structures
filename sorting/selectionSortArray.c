// Takes array of n elements and sorts it in ascending order using selection sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>



void swap(int *a, int *b);
int * generateArray(int size);
void printArray(int * array, int size);
int findmaxindex(int *array, int size);
void selectionSort(int *array, int size); 




int main(int argc, char **argv) 
{
	int * myarr;                            
	int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    // error case in case there are no elements in the list
	if(n < 1) 
    {
        printf("Array has no elements.\n");
        return -1;
    }

	srand(time(NULL));

	myarr = generateArray(n);
	printArray(myarr,n);
	selectionSort(myarr,n);
    printf("Sorted ");
	printArray(myarr,n);

	return 0;
}



void swap(int * a, int * b) //swaps using addresses
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;  
}


int * generateArray(int n) 
{
	int * array = malloc( n * sizeof(int) );
	if(array) 
    {
		for(int i=0; i<n; i++) 
        {
            printf("Enter array element: ");
            scanf("%d", &array[i]);
        }
	}
	return array;
}


void printArray(int * array, int size)
{
    printf("Array: ");
  
    for (int i = 0; i < size; i++)
    {
        
        if (i == 0)
        {
            printf("%i", array[i]);
        }
        else
        {
            printf(", %i", array[i]);
        }
    }
    printf("\n");
    printf("\n");

}



int findmaxindex(int *array, int n) 
{
	int imax; // this will contain the address of the largest element encountered.
	int i;

	imax = 0; // I am assuming that a[0] is the max element
	for (i = 1; i < n; i++) 
    {
		if( array[i] > array[imax] ) 
        {
			imax = i;
		}
	}

	return imax;
}

void selectionSort(int *array, int n) 
{
	int i, imax, t;

	for(i = n; i > 1; i = i-1) 
    {
		imax = findmaxindex(array, i);
		swap(&array[imax], &array[i-1]);
	}
}









