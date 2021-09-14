#include <stdio.h>
#include <stdlib.h>
struct dll
{
    int data;
    struct dll *next;
    struct dll *prev;
};
void insertatbeg(struct dll **head ,int data)
{
    struct dll *newnode = (struct dll *)malloc(sizeof(struct dll));
    newnode->data = data;
    newnode->next = (*head);
    newnode->prev = NULL;
    if((*head) != NULL)
    {
        (*head)->prev = newnode;
    }
    (*head) = newnode;
}
void insertatend(struct dll **head,int data)
{
    struct dll *newnode = (struct dll *)malloc(sizeof(struct dll));
    struct dll *last = *head;
    newnode->data = data;
    newnode->next = NULL;
    if(*head == NULL)
    {
        newnode->prev = NULL;
        *head = newnode;
        return;
    }
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = newnode;
    newnode->prev = last;

    return;
}
void insertafterpos(struct dll *prev_node, int data)
{
    if (prev_node == NULL)
        {
        printf("the given previous node cannot be NULL");
        return;
    }

    struct dll* new_node = (struct dll *)malloc(sizeof(struct dll));

    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}
void display(struct dll *node)
{
    struct dll* last;
    printf("Array is:  ");
    while (node != NULL) {
        printf(" %d ", node->data);

        node = node->next;
    }
    }

int main()
{
    struct dll *head = NULL;
    insertatbeg(&head,9);
    insertatend(&head,8);
    display(&head);
    return 0;
}
