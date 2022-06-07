#include "tarHandler.h"
#include "main.h"
#include "parser.h"

void print_list(header_t* header) // test function to print a list
{
    while(header != NULL)
    {
        printf("name = %s\n", header->name);
        printf("mode = %s\n", header->mode);
        printf("uid = %s\n", header->uid);
        printf("gid = %s\n", header->gid);
        printf("size = %s\n", header->size);
        printf("mtime = %s\n", header->mtime);
        header = header->next;
    }
}

void my_reverse(char str[], int len)
{
    int start, end;
    char temp;
    for(start=0, end=len-1; start < end; start++, end--) {
        temp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = temp;
    }
}

char* my_itoa_base(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;
    if (num == 0) {
        str[i] = '0';
        str[i + 1] = '\0';
        return str;
    }
    if (num < 0 && base == 10) {
        isNegative = true;
        num = -num;
    }  
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
    if (isNegative)
        str[i++] = '-';
    str[i] = ' ';
    str[i+1] = '\0';
    my_reverse(str, i);
    return str;
}

void fill_header(target_t *head, header_t **current)
{
    //printf("start of fill header\n");
    //header_t *current = header_file;
    struct stat filestat;
    int fd = open(head->file_name, O_RDONLY);
    fstat(fd, &filestat); // do some filestat stuff...
    char *name = malloc(sizeof(char) * 100), *mode = malloc(sizeof(char) * 8), *uid = malloc(sizeof(char) * 8), *gid = malloc(sizeof(char) * 8), *size = malloc(sizeof(char) * 12), *mtime = malloc(sizeof(char) * 12);
    name = head->file_name;
    my_itoa_base(filestat.st_mode, mode, 8);
    my_itoa_base(filestat.st_uid, uid, 8);
    my_itoa_base(filestat.st_gid, gid, 8);
    my_itoa_base(filestat.st_size, size, 8);
    my_itoa_base(filestat.st_mtime, mtime, 8);
    //printf("mode = %d, uid = %d, gid = %d, size = %ld, mtime = %ld\n", filestat.st_mode, filestat.st_uid, filestat.st_gid, filestat.st_size, filestat.st_mtime);
    //current->name = head->file_name;
    (*current)->name = head->file_name;
    (*current)->mode = mode;
    (*current)->mode[0] = '0';
    (*current)->uid = uid;
    (*current)->gid = gid;
    (*current)->size = size;
    (*current)->mtime = mtime;
    //header_file->next = NULL;
    (*current)->next = NULL;
    close(fd);
}

void append_header(target_t *head, header_t** header_file) //function to make the header
{
    //printf("start of append header\n");
    header_t *new = malloc(sizeof(header_t));
    (*header_file)->next = new;
    fill_header(head, &new);
    //print_list(header_file);
}

header_t *make_header(target_t *head)
{
    // printf("start of make header\n");
    header_t *header_file = malloc(sizeof(header_t));
    if (head != NULL)
    {
        fill_header(head, &header_file);
        //print_list(header_file);
        while (head->next != NULL && header_file != NULL)
        {
            //printf("if statement\n");
            //printf("start of while loop in make header\n");
            head = head->next;
            //printf("file name = %s\n", head->file_name);
            append_header(head, &header_file);
            //print_list(header_file);
        }
    }
    //print_list(header_file);
    return header_file;
}
void append_archive(archive_t* archive, target_t* target, header_t* header_file)
{
    char *buffer = malloc(BLOCKSIZE);
    buffer[BLOCKSIZE - 1] = '\0';
    memset(buffer, '\0', BLOCKSIZE - 1); 
    int fout = open(archive->archive_name, O_RDWR, O_CREAT); // open the file;
            while (target != NULL)
        {
            int fd = open(target->file_name, O_RDONLY);
            read(fd, buffer, sizeof(buffer)); // read file to buffer
            // read(fout, header_file->name, sizeof(header_t));
            write(fout, header_file->name, strlen(header_file->name));
            write(fout, header_file->mode, strlen(header_file->mode));
            write(fout, header_file->uid, strlen(header_file->uid));
            write(fout, header_file->gid, strlen(header_file->gid));
            write(fout, header_file->size, strlen(header_file->size));
            write(fout, header_file->mtime, strlen(header_file->mtime));
            int readBytes = 0;
            while ((readBytes = read(fd, buffer, BLOCKSIZE)) > 0)
                write(fout, buffer, BLOCKSIZE);
            close(fd);
            target = target->next;
            header_file = header_file->next;
            //print_list(header_file);
        }
        memset(buffer, 0, BLOCKSIZE);   
        write(fout, buffer, BLOCKSIZE);
        write(fout, buffer, BLOCKSIZE);
        close(fout);
}

int tar_function(target_t* target, arg_t* args, archive_t* archive, header_t* header_file) //tar function to write to file out
{
    char *buffer = malloc(BLOCKSIZE);
    buffer[BLOCKSIZE - 1] = '\0';
    memset(buffer, '\0', BLOCKSIZE - 1); 
    //char *buff = malloc(BLOCKSIZE);
    //char buffer[512];
    FILE *output_file = fopen(archive->archive_name, "w");
    int fout = open(archive->archive_name, O_RDWR, O_CREAT); // open the file;
    // printf("size of buffer =  %ld\n", sizeof(buffer));
    if (args->c == true)
    {
        append_archive(archive, target, header_file);
    }
    if (args->r == true || args->u == true)
    {
        append_archive(archive, target, header_file);
    }
    if (args->t == true)
    {
        append_archive(archive, target, header_file);
        write(1, archive->archive_name, sizeof(BLOCKSIZE) * sizeof(header_t));
    }
    if (args->x == true)
    {
        // extract the data
    }

    return 0;
}

void appendItemToArchive()
{

}
