#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    struct nodeType 
    {
        int val;
        struct nodeType *next;
    };

    typedef struct nodeType node;

    // node *head = malloc(sizeof(node));
    // node *temp = malloc(sizeof(node));
    // int i = 0;

    // for (temp = head; temp != NULL; temp = temp->next)
    // {

    // }

    int n = 2;
    // input(n);

    node *head = malloc(sizeof(node));
    node *s = malloc(sizeof(node));
    s = head;

    while(n--)
    {
        int value;
        scanf("%d", &value);

        node *t = malloc(sizeof(node));
        t->val = value;
        t->next = NULL;
      
        t = t->next;
        s = t;
    }


    


}