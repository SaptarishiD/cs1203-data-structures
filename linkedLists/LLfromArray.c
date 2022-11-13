#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int val;
	struct node * next;	
};

typedef struct node * nodeaddress;


int * generateArray(int n);
int * makearray(int size);
nodeaddress linkedListFromArray(int * a, int n);
void freeLinkedList(nodeaddress head);
void printArray(int * a, int n);
void printArray1(int *a, int n);
void printLinkedList(nodeaddress head);

void print_halfLL(nodeaddress head);
 


int main(int argc, char **argv) 
{
	int * a;
	int n = 11;
	//int maxindex;
	//int p, q;
	nodeaddress list;

	srand(time(NULL));

	a = makearray(n);
	list = linkedListFromArray(a,n);

	printArray(a,n);
    printLinkedList(list);

	print_halfLL(list);

	free(a);
	freeLinkedList(list);

	return 0;
}





/* ================================================== */
int * generateArray(int n) 
{
	int * t = malloc( n * sizeof(int) );
	if(t) 
    {
		for(int i=0; i<n; i++) 
        {
            printf("Enter Array Element: ");
            scanf("%d", &t[i]);
        }
	}
	return t;
}

int * makearray(int size) 
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
			array[10] = 17;
        }       
     
	}
	return array;
}

nodeaddress linkedListFromArray(int * a, int n)  // this is linear insertion i think
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

void freeLinkedList(nodeaddress head) 
{
	nodeaddress prev;
	while(head) 
    {
		prev = head;
		head = head->next;
		free(prev);
	}
}

/* ================================================== */
void printArray(int * a, int n) 
{
	printf("Array = ");
	for(int i=0; i<n; i++) 
    {
		printf( i?", %d":"%d", a[i]);
	}
	printf(".\n");
}

void printArray1(int *a, int n) 
{
	for(int i=0; i<n; i++) 
    {
		printf(" %d ", a[i]);
	}
}

void printLinkedList(nodeaddress head) 
{
	nodeaddress c;
	printf("Linked List = ");
	for(c=head; c!=NULL; c=c->next) 
    {
		printf( c==head?"%d":", %d", c->val);
	}
	printf(".\n");
}

// for (node *tmp = list; tmp != NULL; tmp = tmp->next)
//     {
//         printf("%i\n", tmp->number);
//     }


void print_halfLL(nodeaddress head)
{
	// we don't know how many elements are there in the linked list 
	nodeaddress temp = head;
	nodeaddress slow = head;
	nodeaddress fast = head;

	printf("Half Linked List = ");

	if(head)
	{
		while(fast && fast->next)
		{
			printf(" %i ", slow->val);
			fast = fast->next->next;
			slow = slow->next;
		}
	}

	

}