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
void quicksortLL(nodeaddress list);
nodeaddress findTailNode(nodeaddress head);
nodeaddress partitionLL(nodeaddress head, nodeaddress tail);
void quicksort_helper(nodeaddress head, nodeaddress tail);

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
    nodeaddress mylist = linkedlistfromarray(myarr, n);

    printarray(myarr, n);

    quicksortarray(myarr, 0, n-1);

    printf("Sorted ");
    printarray(myarr, n);

    free(myarr);

    printlinkedlist(mylist);

    quicksortLL(mylist);
    printf("Sorted ");

    printlinkedlist(mylist);

    freelinkedlist(mylist);
    return 0;


}

//========================================================================================
//Array Sorting Related

int * generateArray(int size) 
{
	int * array = malloc( size * sizeof(int) );
	if(array) 
    {
		for(int i = 0; i < size; i++) 
        {
            printf("Enter array element: ");
            scanf("%d", &array[i]);
        }
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


nodeaddress linkedlistfromarray(int *array, int size)
{
    nodeaddress head = NULL;
    nodeaddress temp = NULL;

    head = malloc(sizeof(struct node)); //head is now pointer to the first node in the list
    head->val = array[0];
    head->next = NULL;

    temp = head;

    for (int i = 1; i < size; i++)
    {
        temp->next = malloc(sizeof(struct node));  //temp->next is pointer to next node in list
        temp = temp->next;
        temp->val = array[i];
        temp->next = NULL;
    }

    return head;
}


//========================================================================================
//Linked List Sorting Related

nodeaddress findTailNode(nodeaddress list)
{
    nodeaddress temp = list;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp; //this is now the last node in the list
}

void quicksortLL(nodeaddress headoflist)
{
    if(headoflist == NULL)
    {
        return;
    }
    nodeaddress tail = findTailNode(headoflist);
    quicksort_helper(headoflist, tail);

}

void quicksort_helper(nodeaddress headoflist, nodeaddress tail)
{
    if (headoflist == NULL || headoflist == tail)
    {
        return;
    }
    nodeaddress pivot = partitionLL(headoflist, tail);
    quicksort_helper(headoflist, pivot);
    quicksort_helper(pivot->next, tail);
}


nodeaddress partitionLL(nodeaddress headoflist, nodeaddress tail)
{
    nodeaddress pivot = headoflist;
    nodeaddress curr = headoflist->next;
    nodeaddress prev = headoflist;

    while(curr != tail->next)
    {
        if (pivot->val > curr->val)
        {
            swap(&prev->next->val, &curr->val);
            prev = prev->next;
        }
        curr = curr->next;

    }

    swap(&prev->val, &pivot->val);
    return prev;
}




void printlinkedlist(nodeaddress list)
{
    nodeaddress temp = NULL;
    printf("Linked List: ");
    for (temp = list; temp != NULL; temp = temp->next)
    {
        printf(" %i ", temp->val);
    }
    printf("\n");
    printf("\n");
}



void freelinkedlist(nodeaddress list)
{
    nodeaddress temp = NULL;
    temp = list;                
    while(temp != NULL)
    {
        temp = temp->next;
        free(list);
        list = temp;
    }

}
