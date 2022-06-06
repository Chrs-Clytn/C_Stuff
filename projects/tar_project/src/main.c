#include "main.h"
#include "parser.h"
#include "tarHandler.h"

int main(int ac, char **av)
{
    arg_t* args = malloc(sizeof(arg_t));
    args->c = false;
    args->r = false;
    args->t = false;
    args->u = false;
    args->x = false;
    args->f = false;
    archive_t* archive = malloc(sizeof(archive_t));
    archive->archive_name = NULL;
    target_t* target = malloc(sizeof(target_t));
    header_t *header_file = malloc(sizeof(header_t));
    bool parse_args = true;
    //printf("ac = %d\n", ac);
    for(int i = 1; i < ac; i++)
    {
        if(parse_args)
        {
            //printf("parse function, av = %d\n", i);
            parse_function(av[i], args, &parse_args);
        }
        else if(archive->archive_name == NULL)
        {   
            //printf("archive function, av = %d\n", i);
            addArchiveName(av[i], archive);
        }
        else
        {
            //printf("add file,  av = %d\n", i);
            addFile(av[i], target);
        }
    }
    //listPrinter(head, args, archive);
    make_header(target, header_file);
    tar_function(target, args, archive, header_file);   
}