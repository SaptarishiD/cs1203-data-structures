#include <stdio.h>
#include <stdlib.h>


struct node {
	int val;
	struct node * next;  
	struct node * next2;
    struct node * next4; 
};

typedef struct node * nodeaddress;



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


nodeaddress create_skip_list(int * arr, int n)
{
    nodeaddress head = linkedListFromArray(arr, n);
    nodeaddress temp = head;
    nodeaddress temp2nd = temp;

    for (int count = 0; count < 2; count++)
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
        head->next2 = NULL;
    }
    else
    {
        head->next2 = temp2nd;
    }

    // for assigning the 4 skip part
    temp2nd = temp;

    for (int count = 0; count < 4; count++)
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
        head->next4 = NULL;
    }
    else
    {
        head->next4 = temp2nd;
    }


    // rest of the list

    for (int i = 1; i < n; i++)
    {
        temp = temp->next;
        temp2nd = temp;

        if ( i % 2 == 0)
        {
            for (int count = 0; count < 2; count++)
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
                temp->next2 = NULL;
            }
            else
            {
                temp->next2 = temp2nd;
            }
        }

        temp2nd = temp;

        if (i % 4 == 0)
        {
            for (int count = 0; count < 4; count++)
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
                temp->next4 = NULL;
            }
            else
            {
                temp->next4 = temp2nd;
            }

        }

    }

    return head;

}

void printLinkedList(nodeaddress head) 
{
	nodeaddress temp;
    int count = 0;
	printf("Linked List = ");
	for(temp = head; temp != NULL; temp = temp->next) 
    {
		if (temp == head)
        {
            printf("\n");
            printf(" %i) ", count);
            printf("Addr %d ", temp);
            printf("Val %d ", temp->val);
            printf("Next %d ", temp->next);
            printf("next2 %d ", temp->next2);
            printf("next4 %d ", temp->next4);
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
           printf("next2 %d ", temp->next2);
           printf("next4 %d ", temp->next4);
           printf("\n");
           count++;
        }
	}
	printf("\n");
}


int main(void)
{
    int n = 10;
    int * array = makearray(n);

    nodeaddress skiplist = create_skip_list(array, n);

    printLinkedList(skiplist); // prints address of node, value, address of next, next2 and next4




}
