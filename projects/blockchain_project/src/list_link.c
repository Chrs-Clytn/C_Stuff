#include "main.h"
#include "link_list.h"
#include "buff_parse.h"

int my_strcmp(char *param_1, char *param_2)
{
    while ((*param_1 != '\0' && *param_2 != '\0') && *param_1 == *param_2)
    {
        param_1++;
        param_2++;
    }
    if (*param_1 == *param_2)
        return 0;
    else
        return 1;
}

int my_strlen(char *param_1)
{
    int len = 0;
    for (int i = 0; param_1[i]; i++)
        len++;
    return len;
}

block_t *append_block(block_t *head, char *bid)
{
    if (head == NULL)
    {
        block_t *head = (block_t *)malloc(sizeof(block_t));
        head->bid = bid;
        head->next = NULL;
        return head;
    }

    block_t *current = head;
    while (current->next != NULL)
        current = current->next;

    block_t *new = (block_t *)malloc(sizeof(block_t));
    new->next = NULL;
    new->bid = bid;
    current->next = new;

    return head;
};

node_t *append_node(node_t *head, int nid)
{
    if (head == NULL)
    {
        node_t *head = (node_t *)malloc(sizeof(node_t));
        head->nid = nid;
        head->next = NULL;
        return head;
    }
    node_t *current = head;
    while (current->next != NULL)
        current = current->next;
    node_t *new = (node_t *)malloc(sizeof(node_t));
    new->next = NULL;
    new->nid = nid;
    current->next = new;
    return head;
};