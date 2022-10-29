#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int val;
	struct node * next;	
};

typedef struct node * nodeAddress;


int * generateArray(int n);
nodeAddress linkedListFromArray(int * a, int n);
void freeLinkedList(nodeAddress head);
void printArray1(int *a, int n);
void printLinkedList(nodeAddress head);
nodeAddress chunkreverse(nodeAddress head, int chunksize);

 


int main(int argc, char **argv) 
{
	int * a;
	int n = 10;
	//int maxindex;
	//int p, q;
	nodeAddress list;

	srand(time(NULL));

	a = generateArray(n);
	list = linkedListFromArray(a,n);

	printArray1(a,n);
    printLinkedList(list);
    //nodeAddress chunkreversedlist = chunkreverse(list, 3);
    //printLinkedList(chunkreversedlist);
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

nodeAddress linkedListFromArray(int * a, int n)  // this is linear insertion i think
{
	int i;
	nodeAddress head = NULL;
	nodeAddress temp = NULL;

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


void printArray1(int *a, int n) 
{
    printf("Array = ");
	for(int i=0; i<n; i++) 
    {
		printf(" %d ", a[i]);
	}
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
	printf(".\n");
}


nodeAddress chunkreverse(nodeAddress head, int chunksize)
{
    return head;
}

