#include <stdio.h>
#include <stdlib.h>


#define max_stack_size 10
#define max_queue_size 5

int count = 0;
int count2 = 0;

struct node
{
    int val;
    struct node *next;
};

typedef struct node * nodeaddress;

nodeaddress top = NULL;



nodeaddress insert_stack(nodeaddress head, int data)
{
    if (count == max_stack_size)
    {
        printf("Stack overflow while trying to insert %i\n", data);
        return head;

    }

    else
    {   nodeaddress p = NULL;
        nodeaddress temp = malloc(sizeof(struct node));
        temp->val = data;
        temp->next = NULL;

        if (top == NULL)
        {
            top = temp;
            head = top;
        }
        
        else 
        {
            p = head;
            while(p->next != NULL)
            {
                p = p->next;
            }

            p->next = temp;
            top = temp;
        }

        count++;
        return head;
        
    }
}

void extract_stack(nodeaddress head)
{
    if (head && top)
    {
        printf(" %i \n", top->val);

        nodeaddress temp = head;

        if (temp->next)
        {
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = NULL;
            top = temp;
        }

        else if (temp->next == NULL)
        {
            top = NULL;
            head = NULL;
        }

        count--;
        
    
    }

    else if (top == NULL)
    {
        printf("Stack underflow since stack is empty\n");
    }


}



nodeaddress insert_queue(nodeaddress head, int data)
{
    if (count2 == max_queue_size)
    {
        printf("Queue overflow while trying to insert %i\n", data);
        return head;

    }

    else 
    {
        nodeaddress temp = malloc(sizeof(struct node));
        temp->val = data;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            count2++;
        }

        else
        {
            nodeaddress p = head;
            while(p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
            count2++;
        }

        return head;
    }


}


nodeaddress extract_queue(nodeaddress head)
{
    if (head == NULL)
    {
        printf("Queue underflow since queue is empty\n");
        return head;
    }

    else if (head->next)
    {
        nodeaddress temp = head;
        head = head->next;
        printf("%i\n", temp->val);
        count2--;
        return head;
    }

    else if (head->next == NULL)
    {
        printf("%i\n", head->val);
        head = NULL;
        count--;
        return head;
    }

    return head;

}


void printLinkedlist(nodeaddress list)
{
    nodeaddress t = NULL;
    printf("Linked list: ");
    for (t = list; t != NULL; t = t->next)
    {
        printf(" %d ", t->val);
    }
    printf("\n");

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




int main(void)
{

    // nodeaddress stack = NULL;

    // stack = insert_stack(stack, 5);
    // stack = insert_stack(stack, 9);
    // stack = insert_stack(stack, 10);
    // stack = insert_stack(stack, 15);
    // stack = insert_stack(stack, 20);

    // stack = insert_stack(stack, 43);
    // stack = insert_stack(stack, 23);
    // stack = insert_stack(stack, 978);
    // stack = insert_stack(stack, 49);
    // stack = insert_stack(stack, 90);

    // stack = insert_stack(stack, 40);
    // stack = insert_stack(stack, 38);

    // printLinkedstack(stack);

    // extract_stack(stack);
    // extract_stack(stack);
    // extract_stack(stack);
    // extract_stack(stack);
    // extract_stack(stack);

    // extract_stack(stack);
    // extract_stack(stack);
    // extract_stack(stack);
    // extract_stack(stack);
    // extract_stack(stack);

    // extract_stack(stack);

    // stack = insert_stack(stack, 47);
    // stack = insert_stack(stack, 43);

    // extract_stack(stack);
    // extract_stack(stack);

    // extract_stack(stack);

    // stack = insert_stack(stack, 87);

    // extract_stack(stack);

    // freeLinkedList(stack);


    nodeaddress q = NULL;

    q = insert_queue(q, 5);
    q = insert_queue(q, 7);
    q = insert_queue(q, 67);
    q = insert_queue(q, 534);
    q = insert_queue(q, 23);

    q = insert_queue(q, 68);

    printLinkedlist(q);
    printf("Count2: %i\n", count2);

    q = extract_queue(q);
    q = extract_queue(q);
    q = extract_queue(q);
    q = extract_queue(q);
    q = extract_queue(q);
    q = extract_queue(q);

    q = insert_queue(q, 30);
    q = insert_queue(q, 40);

    printLinkedlist(q);

    q = extract_queue(q);
    q = extract_queue(q);

    freeLinkedList(q);

}
