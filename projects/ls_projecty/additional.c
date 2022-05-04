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
    char* tempVar1;
    start = head;
    while(start != NULL)
    {
        temp=start; 
        while (temp->next !=NULL)//travel till the second last element 
        {
           if(temp->time > temp->next->time)// compare the data of the nodes 
            {
              tempvar = temp->time;
              tempVar1 = temp->name;
              temp->time = temp->next->time;// swap the data
              tempVar1 = temp->next->name;
              temp->next->time = tempvar;
              temp->next->name = tempVar1;
            }
         temp = temp->next;    // move to the next element 
        }
        start = start->next;    // move to the next node
    }
}

node *append(node *head, char* dname, char* dtime)
{
    printf("debug 2\n");
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
    printf("debug 3\n");
    node *new = (node *)malloc(sizeof(node));
    new->name = dname;
    new->time = dtime;
    new->next = NULL;
    current->next = new;
    printf("debug 4\n");
    return head;
};

void printerFunction(node* head, int number)
{
    //printf("debug 6\n");
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