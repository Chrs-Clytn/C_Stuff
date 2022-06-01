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
    else if(*param_1 < *param_2)
        return -1;
    else
        return 1;
}

char *int_to_str(unsigned int num, int base) 
{
    char diff_dec[] = "0123456789ABCDEF";
    char buff[50];
    char* point;
    point = &buff[49];
    *point = '\0';

    do
    {
        *--point = diff_dec[num%base];
        num /= base;
    } while (num != 0);

    return(point);
}

bool parse_function(char* av, arg_t* args, bool* argument_parse)
{
    printf("arg value = %s\n", av);
    if(!av || !av[0] || av[0] != '-' || (av[0] == '-' && av[1] == '-') || argument_parse == false)
    {
        *argument_parse = false;
        return false;
    } 
    for(int i = 1; av[i]; i++)
    {
        switch(av[i])
        {
            case 'c':
                args->c = true;
                break;
            case 'r':
                args->r = true;
                break;
            case 't':
                args->t = true;
                break;
            case 'u':
                args->u = true;
                break;
            case 'x':
                args->x = true;
                break;
            case 'f':
                args->f = true;
                break;
            default:
                break;
        }
    }
    *argument_parse = false;
    return true;
}

void listPrinter(target_t* head, arg_t* args, archive_t* archive) //generic list printer
{
    while (head != NULL)
    {
            printf("this shoukd be the target files to tar = %s  ", head->file_name);
            printf("\n");
            head = head->next;
    }
    printf("args c = %s\n", args->c ? "true" : "false");
    printf("args r = %s\n", args->r ? "true" : "false");
    printf("args t = %s\n", args->t ? "true" : "false");
    printf("args u = %s\n", args->u ? "true" : "false");
    printf("args x = %s\n", args->x ? "true" : "false");
    printf("args f = %s\n", args->f ? "true" : "false");
    printf("archive name = %s\n", archive->archive_name);

}