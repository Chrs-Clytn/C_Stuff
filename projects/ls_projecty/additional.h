#ifndef ADDITIONAL_H
#define ADDITIONAL_H

typedef struct s_list
{
    char* name;
    char* time;
    struct s_list *next;
} node;

int my_strcmp(char* param_1, char* param_2);
//node* sortList(node* head);
void printerFunction(node* head, int number);
node *append(node *head, char* dname, char* dtime);

#endif