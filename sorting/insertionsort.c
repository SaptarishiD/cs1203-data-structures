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
void insertsortarray(int * array, int size);
void swap(int * a, int * b);

nodeaddress linkedlistfromarray(int *array, int size);
nodeaddress insortLL(nodeaddress list);
void printlinkedlist(nodeaddress list);
void freelinkedlist(nodeaddress list);


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
    nodeaddress mylist = linkedlistfromarray(myarr, n);

    printarray(myarr, n);

    insertsortarray(myarr, n);

    printf("Sorted ");
    printarray(myarr, n);

    free(myarr);

    printlinkedlist(mylist);

    nodeaddress sortedlist = insortLL(mylist);
    printf("Sorted ");

    printlinkedlist(sortedlist);

    freelinkedlist(mylist);
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



nodeaddress insortLL(nodeaddress list)
{
    // nodeaddress temp = NULL;
    nodeaddress curr = NULL;
    nodeaddress prev = NULL;
    nodeaddress start = malloc(sizeof(struct node)); //spare node which we'll use to point to the list

    start->next = list;
    curr = list;
    // temp = list;
    prev = start;

    // in general shouldnt prev and temp and all increment also somewhere

    while(curr != NULL)
    {
        if (curr->next != NULL && curr->val > curr->next->val)
        {
            while(prev->next != NULL && prev->next->val < curr->next->val)
            {
                prev = prev->next; //finding where to insert
            }

            nodeaddress temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;

            prev = start;
        }

        else
        {
            curr = curr->next; 
        }
    }

    return start->next;


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







