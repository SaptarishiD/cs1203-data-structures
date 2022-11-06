#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int val;
	struct node * next;	
};

typedef struct node * nodeaddress;


int * generateArray(int size);
void printarray(int * array, int size);
void quicksortarray(int * array, int start, int stop);
void swap(int * a, int * b);
int partition(int * array, int start, int stop);


nodeaddress linkedlistfromarray(int *array, int size);
nodeaddress quicksortLL(nodeaddress list);
void printlinkedlist(nodeaddress list);
void freelinkedlist(nodeaddress list);


int main(void)
{
    
    int n;
    srand(time(NULL));
    printf("Enter size of array: ");
    scanf("%d", &n);

    if(n < 1) 
    {
        printf("Array has no elements.\n");
        return -1;
    }

    srand(time(NULL));

    int * myarr = generateArray(n);
    //nodeaddress mylist = linkedlistfromarray(myarr, n);

    printarray(myarr, n);

    quicksortarray(myarr, 0, n-1);

    printf("Sorted ");
    printarray(myarr, n);

    free(myarr);

    // printlinkedlist(mylist);

    // nodeaddress sortedlist = quicksortLL(mylist);
    // printf("Sorted ");

    // printlinkedlist(sortedlist);

    // freelinkedlist(mylist);
    return 0;


}

int * generateArray(int size)
{
    int * array = malloc(size * sizeof(int));
    
    for (int i = 0; i < size; i++)
    {
        array[i] = rand()%1000;
    }

    return array;
}



void printarray(int * array, int size)
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

void quicksortarray(int * array, int start, int stop)
{
    if (start < stop)
    {
        int partindex = partition(array, start, stop);
        quicksortarray(array, start, partindex-1);
        quicksortarray(array, partindex+1, stop);
    }

}

int partition(int * array, int start, int stop)
{

    int pivot = array[start];
    int i = start+1;
    int j = stop;

    while(i <= j)
    {
        if (array[i] > pivot)
        {
            swap(&array[i], &array[j]);
            j = j - 1;
        }

        else
        {
            i = i + 1;
        }
    }

    swap(&array[start], &array[j]); 

    return j;

}

void swap(int * a, int * b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
