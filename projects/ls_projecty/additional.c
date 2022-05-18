#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "additional.h"

int my_strcmp(char* param_1, char* param_2) //my string compare function
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

void sortAlphaNum(node* head)     //sorts my list alhpanumerically by name
{
    node *start = NULL;
    char* tempVar;
    time_t tempVar1;
    start = head;
    while(start->next != NULL) //travel till the second last element
    {
        if(strcmp(start->name, start->next->name) <= 0)  // compare the data of the nodes 
            start = start->next;
        else 
        {
            tempVar = start->next->name;// swap the data
            tempVar1 = start->next->time;
            start->next->name = start->name;
            start->next->time = start->time;
            start->name = tempVar;
            start->time = tempVar1;
        }
    start = start->next; // move to the next element 
    }
}

void sortListTime(node* head) //This function will sort the linked list by time.
{
    node *temp = NULL; // *start = NULL, 
    time_t tempvar;
    char* tempVar1;
    temp = head;
    while (temp->next !=NULL)//travel till the second last element 
    {
        if(temp->time > temp->next->time)// compare the data of the nodes 
        {
            tempvar = temp->time;// swap the data
            tempVar1 = temp->name;
            temp->time = temp->next->time;
            temp->name = temp->next->name;
            temp->next->time = tempvar;
            temp->next->name = tempVar1;
        }
    temp = temp->next;    // move to the next element 
    }
}

node *append(node *head, char* dname, time_t dtime) //this appends to my linked list
{
    if (head->name == NULL)
    {
        head->name = dname;
        head->time = dtime;
        head->next = NULL;
        return head;
    } 
    while (head->next != NULL)
        head = head->next;
    node *new = (node *)malloc(sizeof(node));
    new->name = dname;
    new->time = dtime;
    new->next = NULL;
    head->next = new;
    return head;
};

void listPrinter(node* head) //generic list printer
{
    while (head != NULL)
    {
        printf("%s  ", head->name);
        printf("%ld", head->time);
        printf("\n");
        head = head->next;
    }
    //printf("\n");
}

void printerFunction(node* head, arg_t* args) //printing function to sort through the arguments
{
    sortAlphaNum(head);
    if(args->a == true && args->b == false)
        listPrinter(head);
    if(args->a == false && args->b == false)
    {
        for(int i = 0; i < 2; i++)
            head = head->next;
        listPrinter(head);
    }
    if(args->a == false && args->b == true)
    {
        for(int i = 0; i < 2; i++)
            head = head->next;
        sortListTime(head);
        listPrinter(head);
    }
    if(args->a == true && args->b == true)
    {
        sortListTime(head);
        listPrinter(head);
    }
}