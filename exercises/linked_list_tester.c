#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    int value;
    struct s_list *next;
} node;

node *append(node *head, int value)
{
    if (head == NULL)
    {
        node *head = (node *)malloc(sizeof(node));
        head->value = 2;
        head->next = NULL;
        return head;
    }

    node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    node *new = (node *)malloc(sizeof(node));
    new->next = NULL;
    new->value = value;
    current->next = new;

    return head;
};

node *prepend(node *head, int value)
{
    node *new = (node *)malloc(sizeof(node));
    new->next = head;
    new->value = value;
    head = new;
    return new;
}

int main()
{
    node *head = (node *)malloc(sizeof(node));
    head->value = 2;
    head->next = NULL;

    for (int i = 0; i < 10; i++)
    {
        append(head, i);
    }

    head = prepend(head, 100);

    while (head != NULL)
    {
        printf("%d-", head->value);
        head = head->next;
    }

    return 0;
}