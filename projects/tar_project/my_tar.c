#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "additional.h"

static void addArchiveName(char* av, archive_t* archive)
{
    archive->archive_name = malloc(sizeof(char) * strlen(av) + 1 );
    strcpy(archive->archive_name, av);
}

int tar_function(target_t* target, arg_t* args, archive_t* archive, header_t* header_file)
{
    char buffer[1024];
    //printf("size of buffer =  %ld\n", sizeof(buffer));
    if (args->c == true)
    {
        while (target != NULL)
        {
            int fd = open(target->file_name, O_RDONLY);
            read(fd, buffer, sizeof(buffer));               // read file to buffer
            int fout = open(archive->archive_name, O_RDWR); // open the file
            write(fout, header_file, sizeof(header_t));
            write(fout, buffer, (sizeof(buffer) + 1));      // write buffer to fileout stored in args
            target = target->next;
        }
    }
    //printf("buffer = %s\n", buffer);
    //printf("file out %s\n", archive->archive_name);
    return 0;
}

header_t* make_header(target_t *head)
{
    header_t *header_file = malloc(sizeof(header_t));
    struct stat filestat;
    int fd = open(head->file_name, O_RDONLY);
    fstat(fd, &filestat); // do some filestat stuff...

    if (head != NULL && header_file == NULL)
    {
        header_file->name = head->file_name;
        header_file->mode = int_to_str(filestat.st_mode, 8);
        header_file->uid = int_to_str(filestat.st_uid, 8);
        header_file->gid = int_to_str(filestat.st_gid, 8);
        header_file->size = int_to_str(filestat.st_size, 8);
        header_file->mtime = int_to_str(filestat.st_mtime, 8);
        header_file->next = NULL;
    }
    while (head->next != NULL)
    {
        head = head->next;
        header_t *new = malloc(sizeof(header_t));
        new->name = head->file_name;
        new->mode = int_to_str(filestat.st_mode, 8);
        new->uid = int_to_str(filestat.st_uid, 8);
        new->gid = int_to_str(filestat.st_gid, 8);
        new->size = int_to_str(filestat.st_size, 8);
        new->mtime = int_to_str(filestat.st_mtime, 8);
        new->next = NULL;
        header_file->next = new;
        header_file = header_file->next;
    }
    return header_file;
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
    target_t* head = malloc(sizeof(target_t));
    bool parse_args = true;
    //printf("ac = %d\n", ac);
    for(int i = 1; i < ac; i++)
    {
        if(parse_args)
        {
            printf("parse function, av = %d\n", i);
            parse_function(av[i], args, &parse_args);
        }
        else if(archive->archive_name == NULL)
        {   
            printf("archive function, av = %d\n", i);
            addArchiveName(av[i], archive);
        }
        else
        {
            printf("add file,  av = %d\n", i);
            addFile(av[i], head);
        }
    }
    listPrinter(head, args, archive);
    target_t* header = make_header(head);
    tar_function(head, args, archive, header);   
}