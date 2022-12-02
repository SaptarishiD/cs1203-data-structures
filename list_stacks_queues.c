#include <stdio.h>
#include <stdlib.h>


#define max_stack_size 10
int count = 0;

struct node
{
    int val;
    struct node *next;
};

typedef struct node * nodeaddress;

nodeaddress top = NULL;



nodeaddress insert(nodeaddress head, int data)
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
            list = NULL;
        }

        count--;
        
    
    }

    else if (top == NULL)
    {
        printf("Stack underflow since stack is empty\n");
    }


}



void printLinkedList(nodeaddress list)
{
    nodeaddress t = NULL;
    printf("Linked list: ");
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

    list = insert(list, 43);
    list = insert(list, 23);
    list = insert(list, 978);
    list = insert(list, 49);
    list = insert(list, 90);

    list = insert(list, 40);
    list = insert(list, 38);

    printLinkedList(list);

    extract(list);
    extract(list);
    extract(list);
    extract(list);
    extract(list);

    extract(list);
    extract(list);
    extract(list);
    extract(list);
    extract(list);

    extract(list);

    list = insert(list, 47);
    list = insert(list, 43);

    extract(list);
    extract(list);

    extract(list);

    list = insert(list, 87);

    extract(list);




    
    



}