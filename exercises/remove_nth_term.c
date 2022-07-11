#include <stdlib.h>
#include <stdio.h>
#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
    int val;
    struct s_listnode* next;
} listnode;
#endif

listnode* remove_nth_node_from_end_of_list(listnode* head_ref, int N)
{
    listnode *temp = head_ref, *current, *prev;
    if(head_ref == NULL)
        return NULL;
    
    int count = 0;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    
    count = count - N;
    if(count == 0)
        return head_ref->next;
    current = head_ref;
    prev = NULL;

    while(count > 0)
    {
        prev = current;
        current = current->next;
        count = count - 1;
    }
    prev->next = current->next;
    current->next = NULL;
    free(current);
    return head_ref;
}