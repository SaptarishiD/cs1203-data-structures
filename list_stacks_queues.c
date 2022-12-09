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
            while(p->next != NULL) // this is linear time insertion into the stack
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
            while(temp->next->next != NULL) // linear time extracting from stack
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



// nodeaddress start = NULL;

// nodeaddress enqueue(nodeaddress head, int data)
// {
//     if (count2 == max_queue_size)
//     {
//         printf("Queue overflow while trying to insert %i\n", data);
//         return head;

//     }

//     else 
//     {
//         nodeaddress temp = malloc(sizeof(struct node));
//         temp->val = data;
//         temp->next = NULL;

//         if (head == NULL)
//         {
//             head = temp;
//             start = head;
//             count2++;
//         }

//         else
//         {
//             nodeaddress p = head;
//             while(p->next != NULL)
//             {
//                 p = p->next;
//             }
//             p->next = temp;
//             count2++;
//         }

//         return head;
//     }


// }


// nodeaddress dequeue(nodeaddress head)
// {
//     if (start == NULL)
//     {
//         printf("Queue underflow since queue is empty\n");
//         return head;
//     }

//     else if (head->next)
//     {
//         nodeaddress temp = start;
//         start = start->next;
//         printf("%i\n", temp->val);
//         count2--;
//         return head;
//     }

//     else if (start->next == NULL)
//     {
//         printf("%i\n", start->val);
//         start = NULL;
//         count2--;
//         return head;
//     }

//     return head;

// }

nodeaddress start = NULL;
nodeaddress end = NULL;

void enqueue(nodeaddress head, int data)
{
    nodeaddress newnode = malloc(sizeof(struct node));
    newnode->val = data;
    newnode->next = NULL;

    if (count2 == max_queue_size)
    {
        printf("Queue overflow while trying to insert %i\n", data);
        return;
    }

    if (start == NULL && end == NULL)
    {
        start = newnode;
        end = newnode;
        head = start;
    }

    else 
    {
        end->next = newnode;
        end = end->next;
    }

    printf("End->val: %i\n", end->val); // element which is enqueued

    count2++;
    return;
    
}

void dequeue(nodeaddress head)
{
    if (start == NULL)
    {
        printf("Queue underflow since queue is empty\n");
        return;
    }

    printf("start->val: %i\n", start->val); // element which is dequeued
    nodeaddress temp = start;
    start = start->next;
    head = start;
    free(temp);

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

    // printLinkedlist(stack);

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

    enqueue(q, 18);
    enqueue(q, 7);
    enqueue(q, 67);
    enqueue(q, 534);
    enqueue(q, 23);

    enqueue(q, 68);

    printLinkedlist(q);
    printf("Count2: %i\n", count2);

    dequeue(q);

    //enqueue(q, 38);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    dequeue(q);


    // enqueue(q, 30);
    // enqueue(q, 40);

    // printLinkedlist(q);

    // dequeue(q);
    // dequeue(q);

    freeLinkedList(q);

}
