#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>


#define arraysize 500

void swap(int * a, int * b);
int * generateArray1(int size);
int * generateArray(int size); 
void print_array(int * array, int size);
void build_heap(int * array, int size);
void sift_down(int * array, int i, int size);
int extract_min(int * array, int size);
void insert(int * heaparray, int oldsize, int insertelement);





//should i just do with normal arrays



int main(void)
{
    srand(time(NULL));
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int * array = generateArray1(n);
    printf("Random ");
    print_array(array, n);
    
    build_heap(array, n);
    printf("Heap in form of ");
    print_array(array, n);

    // int minelement = extract_min(heapArray, n);
    // printf("Minimum element = %i\n", minelement);

    // print_array(heapArray, n);
    insert(array, n, 3);
    print_array(array, n+1);







    free(array);
    







}


int * generateArray1(int size) 
{
	int * array = malloc( size * sizeof(int) );
	if(array) 
    {
        for (int i = 0; i < size; i++)
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
            array[9] = 0;
        }       
     
	}
	return array;
}

int * generateArray(int size) 
{
	int * array = malloc( size * sizeof(int) );
	if(array) 
    {
        for (int i = 0; i < size; i++)
        {
            array[i] = rand()%20;
        }       
     
	}
	return array;
}




void print_array(int * array, int size)
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

void swap(int * a, int * b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void build_heap(int * array, int size)
{
    int startindex = (size - 2)/2; // going to the first problem parent since last row is assumed to be heap
    int i = startindex;

    while(i >= 0)
    {
        if (2*i + 1 <= size-1 && 2*i + 2 <= size-1)   // if both left and right child exist within bounds of array
        {
            if (array[i] <= array[2*i + 1] && array[i] <= array[2*i + 2])
            {
                i--;
            }
            else if (array[i] >= array[2*i + 1] && array[i] <= array[2*i + 2])
            {
                swap(&array[i], &array[2*i + 1]);
                sift_down(array, 2*i + 1, size);
                i--;
            }
            else if (array[i] <= array[2*i + 1] && array[i] >= array[2*i + 2])
            {
                swap(&array[i], &array[2*i + 2]);
                sift_down(array, 2*i + 2, size);
                i--;
            }
            else if (array[i] >= array[2*i + 1] && array[i] >= array[2*i + 2])
            {
                if ( array[2*i + 1] <=  array[2*i + 2])
                {
                    swap(&array[i], &array[2*i +1]);
                    sift_down(array, 2*i + 1, size);
                    i--;

                }

                else if ( array[2*i + 1] >=  array[2*i + 2])
                {
                    swap(&array[i], &array[2*i +2]);
                    sift_down(array, 2*i + 2, size);
                    i--;

                }
                // else{i--;}     
            }
        }


        else if (2*i + 1 <= size - 1 && 2*i + 2 > size - 1) // if only left child exists within bounds of array
        {
            if (array[i] <= array[2*i + 1])
            {
                i--;
            }
            else if (array[i] >= array[2*i + 1])
            {
                swap(&array[i], &array[2*i + 1]);
                sift_down(array, 2*i + 1, size);
                i--;
            }
            // else{i--;}           
        }


        else if (2*i + 1 > size - 1 && 2*i + 2 <= size - 1) //if only right child exists within bounds of array
        {
            if (array[i] <= array[2*i + 2])
            {
                i--;
            }
            else if (array[i] >= array[2*i + 2])
            {
                swap(&array[i], &array[2*i + 2]);
                sift_down(array, 2*i + 2, size);
                i--;
            } 
            // else{i--;}          
        }
        // else{i--;}
        
        

    }

    //return array;

    




}

void sift_down(int * array, int i, int size)
{
    if (2*i + 1 <= size-1 && 2*i + 2 <= size-1)
    {
        if (array[i] <= array[2*i + 1] && array[i] <= array[2*i + 2])
        {
            return;
        }
        else if (array[i] >= array[2*i + 1] && array[i] <= array[2*i + 2])
        {
            swap(&array[i], &array[2*i + 1]);
            sift_down(array, 2*i + 1, size);
        }
        else if (array[i] <= array[2*i + 1] && array[i] >= array[2*i + 2])
        {
            swap(&array[i], &array[2*i + 2]);
            sift_down(array, 2*i + 2, size);
        }
        else if (array[i] >= array[2*i + 1] && array[i] >= array[2*i + 2])
        {
            if ( array[2*i + 1] <=  array[2*i + 2])
            {
                swap(&array[i], &array[2*i +1]);
                sift_down(array, 2*i + 1, size);
            }

            else if ( array[2*i + 1] >=  array[2*i + 2])
            {
                swap(&array[i], &array[2*i +2]);
                sift_down(array, 2*i + 2, size);
            }
            // else{return;}
        } 
        // else{return;}
    }


    else if (2*i + 1 <= size - 1 && 2*i + 2 > size - 1) // if only left child exists
    {
        if (array[i] <= array[2*i + 1])
        {
            return;
        }
        else if (array[i] >= array[2*i + 1])
        {
            swap(&array[i], &array[2*i + 1]);
            sift_down(array, 2*i + 1, size);
            
        }
        // else{return;}           
    }


    else if (2*i + 1 > size - 1 && 2*i + 2 <= size - 1) //if only right child exists
    {
        if (array[i] <= array[2*i + 2])
        {
            return;
        }
        else if (array[i] >= array[2*i + 2])
        {
            swap(&array[i], &array[2*i + 2]);
            sift_down(array, 2*i + 2, size);
            
        }
        // else{return;}           
    }
    // else{return;}

}


int extract_min(int * array, int size)
{
    swap(&array[0], &array[size-1]);
    int i = 0;

    sift_down(array, i, size-1);
    return array[size - 1];
}

void insert(int * heaparray, int oldsize, int insertelement)
{
    heaparray = realloc(heaparray, (oldsize+1)*sizeof(int));
    heaparray[oldsize] = insertelement;
    build_heap(heaparray, oldsize+1);
    
}