#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>


#define arraysize 500

void swap(int * a, int * b);
int * generateArray1(int size);
int * generateArray(int size); 
void print_array(int * array, int size);
int * build_heap(int * array, int size);
void sift_down(int * array, int i);



//should i just do with normal arrays



int main(void)
{
    srand(1000);
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int * array = generateArray(n);
    printf("Random ");
    print_array(array, n);
    
    int * heapArray = build_heap(array, n);
    printf("Heap in form of ");
    print_array(heapArray, n);



    free(array);







}


int * generateArray1(int size) 
{
	int * array = malloc( size * sizeof(int) );
	if(array) 
    {
        for (int i = 0; i <= size; i++)
        {
            array[0] = 15;
            array[1] = 10;
            array[2] = 2;
            array[3] = 19;
            array[4] = 5;
            array[5] = 20;
            array[6] = 4;
            array[7] = 19;
            array[8] = 6;
            array[9] = 21;
        }       
     
	}
	return array;
}

int * generateArray(int size) 
{
	int * array = malloc( size * sizeof(int) );
	if(array) 
    {
        for (int i = 0; i <= size; i++)
        {
            array[i] = rand()%25;
        }       
     
	}
	return array;
}




void print_array(int * array, int size)
{
    printf("Array: ");
  
    for (int i = 0; i <= size; i++)
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

void swap(int * a, int * b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


int * build_heap(int * array, int size)
{
    int startindex = (size - 2)/2; // going to the first problem parent since last row is assumed to be heap
    int i = startindex;

    while(i >= 0)
    {
        if (array[2*i + 1] && array[2*i + 2])   // if both left and right child exist
        {
            if (array[i] <= array[2*i + 1] && array[i] <= array[2*i + 2])
            {
                i--;
            }
            else if (array[i] >= array[2*i + 1] && array[i] <= array[2*i + 2])
            {
                swap(&array[i], &array[2*i + 1]);
                sift_down(array, 2*i + 1);
                i--;
            }
            else if (array[i] <= array[2*i + 1] && array[i] >= array[2*i + 2])
            {
                swap(&array[i], &array[2*i + 2]);
                sift_down(array, 2*i + 2);
                i--;
            }
            else if (array[i] >= array[2*i + 1] && array[i] >= array[2*i + 2])
            {
                if ( array[2*i + 1] <=  array[2*i + 2])
                {
                    swap(&array[i], &array[2*i +1]);
                    sift_down(array, 2*i + 1);
                    i--;

                }

                else if ( array[2*i + 1] >=  array[2*i + 2])
                {
                    swap(&array[i], &array[2*i +2]);
                    sift_down(array, 2*i + 2);
                    i--;

                }
                // else{i--;}     
            }
        }


        else if (array[2*i + 1] && !array[2*i + 2]) // if only left child exists
        {
            if (array[i] <= array[2*i + 1])
            {
                i--;
            }
            else if (array[i] >= array[2*i + 1])
            {
                swap(&array[i], &array[2*i + 1]);
                sift_down(array, 2*i + 1);
                i--;
            }
            // else{i--;}           
        }


        else if (!array[2*i + 1] && array[2*i + 2]) //if only right child exists
        {
            if (array[i] <= array[2*i + 2])
            {
                i--;
            }
            else if (array[i] >= array[2*i + 2])
            {
                swap(&array[i], &array[2*i + 2]);
                sift_down(array, 2*i + 2);
                i--;
            } 
            // else{i--;}          
        }
        // else{i--;}
        
        

    }

    return array;

    




}

void sift_down(int * array, int i)
{
    if (array[2*i + 1] && array[2*i + 2])
    {
        if (array[i] <= array[2*i + 1] && array[i] <= array[2*i + 2])
        {
            return;
        }
        else if (array[i] >= array[2*i + 1] && array[i] <= array[2*i + 2])
        {
            swap(&array[i], &array[2*i + 1]);
            sift_down(array, 2*i + 1);
        }
        else if (array[i] <= array[2*i + 1] && array[i] >= array[2*i + 2])
        {
            swap(&array[i], &array[2*i + 2]);
            sift_down(array, 2*i + 2);
        }
        else if (array[i] >= array[2*i + 1] && array[i] >= array[2*i + 2])
        {
            if ( array[2*i + 1] <=  array[2*i + 2])
            {
                swap(&array[i], &array[2*i +1]);
                sift_down(array, 2*i + 1);
            }

            else if ( array[2*i + 1] >=  array[2*i + 2])
            {
                swap(&array[i], &array[2*i +2]);
                sift_down(array, 2*i + 2);
            }
            // else{return;}
        } 
        // else{return;}
    }


    else if (array[2*i + 1] && !array[2*i + 2]) // if only left child exists
    {
        if (array[i] <= array[2*i + 1])
        {
            return;
        }
        else if (array[i] >= array[2*i + 1])
        {
            swap(&array[i], &array[2*i + 1]);
            sift_down(array, 2*i + 1);
            
        }
        // else{return;}           
    }


    else if (!array[2*i + 1] && array[2*i + 2]) //if only right child exists
    {
        if (array[i] <= array[2*i + 2])
        {
            return;
        }
        else if (array[i] >= array[2*i + 2])
        {
            swap(&array[i], &array[2*i + 2]);
            sift_down(array, 2*i + 2);
            
        }
        // else{return;}           
    }
    // else{return;}

}