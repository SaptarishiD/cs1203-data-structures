#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct node {
	int val;
	struct node * next;  
	struct node * nextk1;
    struct node * nextk2; 
};

typedef struct node * nodeaddress;

int * generateArray(int size);
void quicksortarray(int * array, int start, int stop);
int partition(int * array, int start, int stop);
void swap(int * a, int * b);

int rand_val_of_k(void);
nodeaddress linkedListFromArray(int * a, int n);
nodeaddress create_skip_list(int * arr, int n);
void printskiplist(nodeaddress head);



int main(void)
{
    srand(time(0));
    int n;
    printf("Enter length of skip list: ");
    scanf("%d", &n);
    int * array = generateArray(n);

    quicksortarray(array, 0, n-1);

    nodeaddress skiplist = create_skip_list(array, n);

    printskiplist(skiplist); // prints address of node, value, address of next, nextk1 and nextk2

}



int rand_val_of_k(void) // generates random value of 1 < k <= 5
{    
    int result = (rand()%5) + 2;
    return result;
}

int * makearray(int size) 
{
	int * array = malloc( size * sizeof(int) );
	if(array) 
    {
        for (int i = 0; i < size; i++)
        {
            array[0] = 1;
            array[1] = 8;
            array[2] = 10;
            array[3] = 12;
            array[4] = 14;
            array[5] = 16;
            array[6] = 18;
            array[7] = 20;
            array[8] = 21;
            array[9] = 22;
        }       
     
	}
	return array;
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


nodeaddress linkedListFromArray(int * a, int n) 
{
	int i;
	nodeaddress head = NULL;
	nodeaddress temp = NULL;

	// special case for head
	if(n>0) 
    {
		head = malloc( sizeof(struct node) );
		head->val  = a[0];
		head->next = NULL;
		temp = head;
	}


	for(i=1; i<n; i++) 
    {
		temp->next = malloc( sizeof(struct node) );
		temp = temp->next;
		temp->val = a[i];
		temp->next = NULL;
	}

	return head;
}


nodeaddress create_skip_list(int * arr, int n)
{
    nodeaddress head = linkedListFromArray(arr, n);
    nodeaddress temp = head;
    nodeaddress temp2nd = temp;

    int firstjumpval = rand_val_of_k();
    int secondjumpval = 2*firstjumpval;

    printf(" k1 : %i\n ", firstjumpval);
    printf(" k2 : %i\n ", secondjumpval);

    for (int count = 0; count < firstjumpval; count++)
    {
        if (temp2nd == NULL)
        {
            break;
        }
        else
        {
            temp2nd = temp2nd->next;
        }
    }

    if (temp2nd == NULL)
    {
        head->nextk1 = NULL;
    }
    else
    {
        head->nextk1 = temp2nd;
    }

    // for assigning the 4 skip part
    temp2nd = temp;

    for (int count = 0; count < secondjumpval; count++)
    {
        if (temp2nd == NULL)
        {
            break;
        }
        else
        {
            temp2nd = temp2nd->next;
        }
    }

    if (temp2nd == NULL)
    {
        head->nextk2 = NULL;
    }
    else
    {
        head->nextk2 = temp2nd;
    }


    // rest of the list

    for (int i = 1; i < n; i++)
    {
        temp = temp->next;
        temp2nd = temp;

        if ( i % firstjumpval == 0)
        {
            for (int count = 0; count < firstjumpval; count++)
            {
                if (temp2nd == NULL)
                {
                    break;
                }
                else
                {
                    temp2nd = temp2nd->next;
                }
            }
            if (temp2nd == NULL)
            {
                temp->nextk1 = NULL;
            }
            else
            {
                temp->nextk1 = temp2nd;
            }
        }

        temp2nd = temp;

        if (i % secondjumpval == 0)
        {
            for (int count = 0; count < secondjumpval; count++)
            {
                if (temp2nd == NULL)
                {
                    break;
                }
                else
                {
                    temp2nd = temp2nd->next;
                }
            }
            if (temp2nd == NULL)
            {
                temp->nextk2 = NULL;
            }
            else
            {
                temp->nextk2 = temp2nd;
            }

        }

    }

    return head;

}

void printskiplist(nodeaddress head) 
{
	nodeaddress temp;
    int count = 0;
	printf("Skip List = ");
	for(temp = head; temp != NULL; temp = temp->next) 
    {
		if (temp == head)
        {
            printf("\n");
            printf(" %i) ", count);
            printf("Addr %d ", temp);
            printf("Val %d ", temp->val);
            printf("Next %d ", temp->next);
            printf("nextk1 %d ", temp->nextk1);
            printf("nextk2 %d ", temp->nextk2);
            printf("\n");
            count++;

        }
        else
        {
           printf("\n");
           printf(" %i) ", count );
           printf("Addr %d ", temp);
           printf("Val %d ", temp->val);
           printf("Next %d ", temp->next);
           printf("nextk1 %d ", temp->nextk1);
           printf("nextk2 %d ", temp->nextk2);
           printf("\n");
           count++;
        }
	}
	printf("\n");
}


