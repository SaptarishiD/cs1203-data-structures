#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int * generateArray(int size);
void printarray(int * array, int size);
void insertsortarray(int * array, int size);
void swap(int * a, int * b);


int main(void)
{
    
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    if(n < 1) 
    {
        printf("Array has no elements.\n");
        return -1;
    }

    srand(time(NULL));

    int * myarr = generateArray(n);
    printarray(myarr, n);

    insertsortarray(myarr, n);

    printf("Sorted ");
    printarray(myarr, n);

    free(myarr);
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






void insertsortarray(int * array, int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (array[j-1] > array[j])
            {
                swap(&array[j-1], &array[j]);
            }
        }
    }




}

void swap(int * a, int * b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}




