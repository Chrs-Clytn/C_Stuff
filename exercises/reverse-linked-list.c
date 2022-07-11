#include <stdio.h>
#include <stdlib.h>
#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
    int val;
    struct s_listnode* next;
} listnode;
#endif

//to reverse we need to go to the end of the list before NULL, and make that node point to the previous node
//make a temp head node pointing to the current node
//make all previous nodes point to the previous node
//make first node point to null
//make head node point last node

listnode* reverse_linked_list(listnode* head)
{
    // if (head == NULL)
    // {
    //     listnode *head = (listnode *)malloc(sizeof(listnode));
    //     head->val = 2;
    //     head->next = NULL;
    //     return head;
    // }

    listnode *current = head;
    listnode* next = NULL;
    listnode* previous = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = previous; //reverses the current nodes pointer
        previous = current; //move the pointer
        current = next;
    }

    head = previous;
}

listnode *append(listnode *head, int value)
{
    if (head == NULL)
    {
        listnode *head = (listnode *)malloc(sizeof(listnode));
        head->val = value;
        head->next = NULL;
        return head;
    }

    listnode *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    listnode *new = (listnode *)malloc(sizeof(listnode));
    new->next = NULL;
    new->val = value;
    current->next = new;

    return head;
}

int main()
{
    // //listnode *head = (listnode *)malloc(sizeof(listnode));
    // head->val = 2;
    // head->next = NULL;
    listnode* head = NULL;

    for (int i = 0; i < 10; i++)
    {
        head = append(head, i);
    }

    //head = prepend(head, 100);

    // while (head != NULL)
    // {
    //     printf("%d-", head->val);
    //     head = head->next;
    // }
    // printf("\n");

    head = reverse_linked_list(head);
    printf("head val = %d\n", head->val);
    
    while (head != NULL)
    {
        printf("%d-", head->val);
        head = head->next;
    }
    printf("\n");

    return 0;
}