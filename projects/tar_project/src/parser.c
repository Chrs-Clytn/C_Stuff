#include "parser.h"
#include "main.h"

void addArchiveName(char* av, archive_t* archive)
{
    archive->archive_name = av; //malloc(sizeof(char) * strlen(av) + 1 );
    //archive->archive_file = av;
    //strcpy(archive->archive_name, av);
}

target_t* addFile(char* av, target_t* head)
{
    if(head->file_name == NULL)
    {
        head->file_name = av;
        head->next = NULL;
        return head;
    }
    while (head->next != NULL)
        head = head->next;
    target_t* new = malloc(sizeof(target_t));
    new->file_name = av;
    new->next = NULL;
    head->next = new;
    return head;
}

bool parse_function(char* av, arg_t* args, bool* argument_parse)
{
    //printf("arg value = %s\n", av);
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