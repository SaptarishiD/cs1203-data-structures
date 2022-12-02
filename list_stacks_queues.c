#include <stdio.h>
#include <stdlib.h>


#define stacksize 10

struct node
{
    int val;
    struct node *next;
};

typedef struct node * nodeaddress;

nodeaddress top = NULL;



nodeaddress insert(nodeaddress head, int data)
{
    nodeaddress p = NULL;
    nodeaddress temp = malloc(sizeof(struct node));
    temp->val = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        top = head;
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

    return head;
}

void extract(nodeaddress list)
{

    if (list && top)
    {
        printf(" %i \n", top->val);

        nodeaddress temp = list;

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

        }
        
        

    }

    else if (top == NULL)
    {
        printf("Stack empty\n");
    }

}



void printLinkedList(nodeaddress list)
{
    nodeaddress t = NULL;
    for (t = list; t != NULL; t = t->next)
    {
        printf(" %d ", t->val);
    }
    printf("\n");

}



int main(void)
{

    nodeaddress list = NULL;

    list = insert(list, 5);
    list = insert(list, 9);
    list = insert(list, 10);
    list = insert(list, 15);
    list = insert(list, 20);

    printLinkedList(list);

    extract(list);
    extract(list);
    extract(list);
    extract(list);

    extract(list);
    extract(list);


    //printLinkedList(list);





}