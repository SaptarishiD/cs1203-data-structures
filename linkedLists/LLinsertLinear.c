#include <stdio.h>
#include <stdlib.h>



typedef struct nodeType
{
    int val;
    struct nodeType *next;
}node;

node * createLinkedList(int n);
void printLinkedList(node *list);

int main(void)
{
    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    node *list = NULL;
    list = createLinkedList(size);
    printLinkedList(list);

    while (list != NULL)
    {
        // We point to the next node first
        node *tmp = list->next;
        // Then, we can free the first node
        free(list);
        // Now we can set the list to point to the next node
        list = tmp;
        // If list is null, when there are no nodes left, our while loop will stop
    }
}


node * createLinkedList(int n)
{
    node *head = NULL;
    // node *temp = NULL;
    node *p = NULL;

    int i;

    for (i = 0; i < n; i++)
    {
        node *temp = malloc(sizeof(node));
        printf("Enter value: ");
        scanf("%d", &(temp->val));
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
        }

        else
        {
            p = head;
            while(p->next != NULL)
            {
                p = p->next;
            }

            // p->next->val = temp->val;
            // p->next->next = NULL; why didnt this work

            p->next = temp;
        }   
    }
    return head;
}



void printLinkedList(node *list)
{
    node *t = NULL;
    for (t = list; t != NULL; t = t->next)
    {
        printf("%d ", t->val);
    }
    printf("\n");

}
