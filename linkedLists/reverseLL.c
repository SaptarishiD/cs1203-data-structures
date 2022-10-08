#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int value;
    struct node *next;
}node;

node *createLinkedList(int size);
void printLinkedList(node *list);
node *reverseLinkedList(node *mylist);
void freeLinkedList(node *mylist);


int main(int argc, char **argv)
{
    int size;
    printf("Enter size of linked list: ");
    scanf("%d", &size);
    node *list = NULL;
    list = createLinkedList(size);
    printLinkedList(list);
    node *newList = reverseLinkedList(list);
    printLinkedList(newList);

}





node *createLinkedList(int size)
{
    node *head = NULL;
    int i;

    for (i = 0; i < size; i++)
    {
        node *temp = malloc(sizeof(node));
        printf("Enter Value for Linked List: ");
        scanf("%d", &(temp->value));                
        temp->next = NULL;

        if (head == NULL)   //if its the first node 
        {
            head = temp;
        }

        else 
        {
            temp->next = head;  //since we're doing const time inserting, the temp node pointer points to the whole list
            head = temp;        //then the head points to the new node so it points to the new whole list
        }

       

    }

    return head;
}


void printLinkedList(node *list)
{   
    node *temp = malloc(sizeof(node));

    for (temp = list; temp != NULL; temp = temp->next)
    {
        printf("%d ", temp->value);
    }
    printf("\n");
}


node *reverseLinkedList(node *mylist)
{
    node *prev = NULL;
    node *following = NULL;
    node *current = mylist;

    while (current != NULL)
    {
        following = current->next; 
        current->next = prev;
        prev = current;
        current = following;
    }

    return current; //current will now work because at the end current gets the value following which is NULL so 
                    //returning current will return NULL, so we need to return prev instead

}



void freeLinkedList(node *mylist)
{

}