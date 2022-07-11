#include <stdio.h>
#include <stdlib.h>
typedef struct s_list
{
  int value;
  struct s_list *next;
} t_list;

t_list *newElem(t_list *head, int value)
{
    if (head == NULL)
    {
      t_list *head = (t_list *)malloc(sizeof(t_list));
      head->value = value;
      head->next = NULL;
      return head;
    }
    t_list *list = head;
    while (list->next != NULL)
    {
      list = list->next;
    }
    t_list *newElem = (t_list *)malloc(sizeof(t_list));
    newElem->value = value;
    list->next = newElem;
    return head;
}

void printList(t_list *head)
{
    while (head != NULL)
    {
      printf("%d,", head->value);
      head = head->next;
    }
    printf("\n");
  }

t_list *mergeList(t_list *list_a, t_list *list_b)
{
    t_list *head = NULL;
    if (list_a->value > list_b->value)
    {
      head = list_b;
      list_b = list_b->next;
    }
    else
    {
      head = list_a;
      list_a = list_a->next;
    }
    t_list *curr = head;
    while (list_a != NULL || list_b != NULL)
    {
      if (list_a == NULL || list_a->value > list_b->value)
      {
        curr->next = list_b;
        list_b = list_b->next;
      }
      else
      {
        curr->next = list_a;
        list_a = list_a->next;
      }
      curr = curr->next;
    }
    return head;
  }

int main()
{
    t_list *List1 = NULL;
    t_list *List2 = NULL;
    List1 = newElem(List1, 1);
    newElem(List1, 2);
    newElem(List1, 4);
    List2 = newElem(List2, 1);
    newElem(List2, 3);
    newElem(List2, 4);
    t_list *newLst = mergeList(List1, List2);
    printList(newLst);
    return 0;
}