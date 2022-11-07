//sorts linked list using selection sort by swapping the data at the nodes and not the nodes themselves


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int val;
	struct node * next;	
};

typedef struct node * nodeAddress;


void swap(int *x, int *y);

int * generateArray(int n);
nodeAddress linkedListFromArray(int * a, int n);
void freeLinkedList(nodeAddress head);
void printArray(int * a, int n);
void printLinkedList(nodeAddress head);
int findIndexOfMax(int *a, int n);
void selectionSort(int *a, int n);
void selsortLL(nodeAddress head);
void dataswap(nodeAddress min, nodeAddress temp);
nodeAddress findMinValNode(nodeAddress forward, nodeAddress min);







int main(int argc, char **argv) 
{
	int * a;
	int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
	nodeAddress list;

	srand(time(NULL));

	a = generateArray(n);
	list = linkedListFromArray(a,n);

	printArray(a,n);

    printLinkedList(list);    
    selsortLL(list);
    printf("Sorted ");
    printLinkedList(list);


	free(a);
	freeLinkedList(list);

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

nodeAddress linkedListFromArray(int * a, int n) // generates linked list from array with the data in the same order as the array
{
	int i;
	nodeAddress head = NULL;
	nodeAddress temp = NULL;

	if(n > 0) 
    {
		head = malloc(sizeof(struct node)); //special case for head
		head->val  = a[0];
		head->next = NULL;
		temp = head;
	}


	for(i = 1; i < n; i++) 
    {
		temp->next = malloc(sizeof(struct node));
		temp = temp->next;
		temp->val = a[i];
		temp->next = NULL;
	}

	return head;
}

void freeLinkedList(nodeAddress head) 
{
	nodeAddress prev;
	while(head) 
    {
		prev = head;
		head = head->next;
		free(prev);
	}
}



void printArray(int *a, int n) 
{
    printf("Array = ");
	for(int i = 0; i < n; i++) 
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

void printLinkedList(nodeAddress head) 
{
	nodeAddress c;
	printf("Linked List = ");
	for(c=head; c!=NULL; c=c->next) 
    {
		printf( c==head?"%d":", %d", c->val);
	}
	printf("\n");
    printf("\n");
}


void dataswap(nodeAddress min, nodeAddress temp) //swaps data between nodes
{
    int tempint = min->val;
    min->val = temp->val;
    temp->val = tempint;
    temp = temp->next;
}



nodeAddress findMinValNode(nodeAddress forward, nodeAddress min)
{
    while(forward)                      // finds the minimum element in the linked list and returns the respective node
        {
            if (forward->val < min->val)
            {
                min = forward;
            }
            forward = forward->next;
        }
    return min;
}



void selsortLL(nodeAddress head)
{
   
    nodeAddress temp = head;

    while (temp)
    {
        nodeAddress min = temp;
        nodeAddress forward = temp->next;

        min = findMinValNode(forward, min);
        int tempint = min->val;
        min->val = temp->val;
        temp->val = tempint;

        temp = temp->next;

    }
}

