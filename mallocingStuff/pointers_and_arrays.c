#include <stdio.h>
#include <stdlib.h>

void printarray(int * array, int size);



int main(void)
{
    int n = 5;
    int * firstarr = malloc(n*sizeof(int));

    if (firstarr == NULL)
    {
        printf("Malloc error\n");
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        firstarr[i] = 2*i;
    }
    printf("First ");
    printarray(firstarr, n);


    int * secondarr = realloc(firstarr, n*2);

    if (secondarr == NULL)
    {
        printf("Realloc error\n");
        return 2;
    }

    for (int i = n; i < n*2; i++)
    {
        secondarr[i] = 2*i;
    }


    printf("Junk values in first ");
    printarray(firstarr, n); // when i print first array here it prints junk values except second last and last element
    printf("Second ");
    printarray(secondarr, n*2);

    free(firstarr);
    free(secondarr);


    
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