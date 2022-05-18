#include <stdbool.h>
#include <time.h>
#ifndef ADDITIONAL_H
#define ADDITIONAL_H

typedef struct s_list //defining struct for my linked list
{
    char* name;
    time_t time;
    struct s_list *next;
} node;

typedef struct s_arg //defining struct for my arguments
{
    bool a;
    bool b;
} arg_t;

int my_strcmp(char* param_1, char* param_2);
//node* sortList(node* head);
void printerFunction(node* head, arg_t* args);
node *append(node *head, char* dname, time_t dtime);

#endif