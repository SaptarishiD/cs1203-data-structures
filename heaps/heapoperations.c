#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * generateHeapArray(int n);
void printArray(int *a, int n); 
int extractMin(int * array, int size);
void swap(int * a, int * b);


//add comments for everything




int main(void)
{   
    int size = 10;
    int * array = generateHeapArray(size);
    printArray(array, size);
    // int myarray[] = {99, 88, 73, 69, 57, 49, 42, 35, 20, 11, 4, 3};
    
    // for (int i = 0; i < 12; i++)
    // {
    //     printf(" %i ", myarray[i]);
    // }
    // printf("\n");

    int extractedelement = extractMin(array, size);
    printf("%i\n", extractedelement);
    printArray(array, size);



    free(array);
}


int * generateHeapArray(int n)
{
    int * t = malloc( n * sizeof(int) );
	if(t) 
    {
		for(int i=0; i<n; i++) 
        {
            t[i] = i*11;
        }
	}
	return t;
}

void printArray(int *a, int n) 
{
    printf("Array = ");
	for(int i=0; i<n; i++) 
    {
		if (i == 0)
        {
            printf(" %d", a[i]);
	    }
        else
        {
            printf(", %d ", a[i]);
        }
    }
    printf("\n");
    printf("\n");
}



int extractMin(int * array, int size)
{
    swap(&array[0], &array[size-1]);
    int i = 0;

    while(i < size - 1)
    {

        if (array[i] < array[2*i + 1] && array[i] < array[2*i + 2])
        {
            return array[size - 1];
        }

        else if (array[i] < array[2*i + 1] && array[i] > array[2*i +2])
        {
            swap(&array[i], &array[2*i +2]);
        }
        else if (array[i] > array[2*i + 1] && array[i] < array[2*i +2])
        {
            swap(&array[i], &array[2*i +1]);
        }

        else
        {
            if ( array[2*i + 1] <  array[2*i + 2])
            {
                swap(&array[i], &array[2*i +1]);
            }

            else if ( array[2*i + 1] >  array[2*i + 2])
            {
                swap(&array[i], &array[2*i +2]);
            }
        }

        i = i+1;

    }
    return array[size - 1];



    //return array[size - 1];
}


void swap(int * a, int * b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
























//               00
//            /     \
//           11      22
//          /  \    /  \
//        33   44  55   66 
//     /  \   /
//    77  88  99

//if have to do insert and extract stuff on array then have to resize and stuff?