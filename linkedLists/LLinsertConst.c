#include <stdio.h>
#include <stdlib.h>



typedef struct nodeType
{
    int val;
    struct nodeType *next;
}node;

node * createLinkedList(int n);
void printLinkedList(node *list);
void freeLinkedList(node *list);

int main(void)
{
    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    node *list = NULL;
    list = createLinkedList(size);
    printLinkedList(list);

    freeLinkedList(list);
}


node * createLinkedList(int n)
{
    node *head = NULL;
    // node *temp = NULL;
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
            temp->next = head;
            head = temp;
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

void freeLinkedList(node *list)
{
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}
