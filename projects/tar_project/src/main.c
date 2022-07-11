#include "main.h"
#include "parser.h"
#include "tarHandler.h"

int main(int ac, char **av)
{
    arg_t* args = malloc(sizeof(arg_t));
    archive_t* archive = malloc(sizeof(archive_t));
    target_t* target = malloc(sizeof(target_t));
    args->c = false, args->r = false, args->t = false, args->u = false, args->x = false, args->f = false, archive->archive_name = NULL;
    bool parse_args = true;
    for(int i = 1; i < ac; i++)
    {
        if(parse_args)
        {
            //printf("parse function, av = %d\n", i);
            parse_function(av[i], args, &parse_args);
        }
        else if(archive->archive_name == NULL && args->f == true)
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
    header_t* header_file = make_header(target);
    tar_function(target, args, archive, header_file);   
}