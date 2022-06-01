#include "tarHandler.h"
#include "main.h"
#include "parser.h"

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

int tar_function(target_t* target, arg_t* args, archive_t* archive, header_t* header_file)
{
    char buffer[1024];
    int fout = open(archive->archive_name, O_RDWR, O_CREAT); // open the file;
    //printf("size of buffer =  %ld\n", sizeof(buffer));
    if (args->c == true)
    {
        while (target != NULL)
        {
            int fd = open(target->file_name, O_RDONLY);
            read(fd, buffer, sizeof(buffer));               // read file to buffer 
            write(fout, header_file, sizeof(header_t));
            write(fout, buffer, (sizeof(buffer) + 1));      // write buffer to fileout stored in args
            target = target->next;
        }
    }
    //printf("buffer = %s\n", buffer);
    //printf("file out %s\n", fout);
    write(1, buffer, (sizeof(buffer) + 1));
    return 0;
}