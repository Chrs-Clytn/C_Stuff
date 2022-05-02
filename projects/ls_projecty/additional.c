#include <stdio.h>
#include <stdlib.h>
#include "additional.h"

int my_strcmp(char* param_1, char* param_2)
{
    while(( *param_1 != '\0' && *param_2 != '\0' ) && *param_1 == *param_2)
    {
        param_1++;
        param_2++;
    }
    if(*param_1 == *param_2)
        return 0; 
    else
        return 1;
}

void sortList(node* head)
{
    node *start = NULL, *temp = NULL;
    char* tempvar;
    start = head;
    while(start != NULL)
    {
        temp=start; 
        while (temp->time !=NULL)//travel till the second last element 
        {
           if(temp->time > temp->next->time)// compare the data of the nodes 
            {
              tempvar = temp->time;
              temp->time = temp->next->time;// swap the data
              temp->next->time = tempvar;
            }
         temp = temp->next;    // move to the next element 
        }
        start = start->next;    // move to the next node
    }
}

node *append(node *head, char* dname, char* dtime)
{
    if (head->name == NULL)
    {
        head->name = dname;
        head->time = dtime;
        head->next = NULL;
        return head;
    }

    node *current = head;
    while (current->next != NULL)
        current = current->next;

    node *new = (node *)malloc(sizeof(node));
    new->next = NULL;
    new->name = dname;
    new->time = dtime;
    current->next = new;

    return head;
};

void printerFunction(node* head, int number)
{
    if(number == 2)
    {
        while (head != NULL)
        {
            printf("%s-", head->name);
            printf("%s-", head->time);
            printf("\n");
            head = head->next;
        }
    }
    if(number == 0)
    {
        for(int i = 0; i < 2; i++)
            head = head->next;
        while (head != NULL)
        {
            printf("%s-", head->name);
            printf("%s-", head->time);
            printf("\n");
            head = head->next;
        }
    }
    if(number == 5)
    {
        for(int i = 0; i < 2; i++)
            head = head->next;
        sortList(head);
        while (head != NULL)
        {
            printf("%s-", head->name);
            printf("%s-", head->time);
            printf("\n");
            head = head->next;
        }
    }
}