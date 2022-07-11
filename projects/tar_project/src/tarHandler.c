#include "tarHandler.h"
#include "main.h"
#include "parser.h"

// void print_list(header_t* header) // test function to print a list
// {
//     while(header != NULL)
//     {
//         printf("name = %s\n", header->name);
//         printf("mode = %s\n", header->mode);
//         printf("uid = %s\n", header->uid);
//         printf("gid = %s\n", header->gid);
//         printf("size = %s\n", header->size);
//         printf("mtime = %s\n", header->mtime);
//         header = header->next;
//     }
// }

void my_reverse(char str[], int len) // reverse function to work with itoa
{
    int start, end;
    char temp;
    for (start = 0, end = len - 1; start < end; start++, end--)
    {
        temp = *(str + start);
        *(str + start) = *(str + end);
        *(str + end) = temp;
    }
}

char *my_itoa_base(int num, char *str, int base) // function to replicate itoa
{
    int i = 0;
    bool isNegative = false;
    if (num == 0)
    {
        str[i] = '0';
        str[i + 1] = '\0';
        return str;
    }
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }
    if (isNegative)
        str[i++] = '-';
    str[i] = ' ';
    str[i + 1] = '\0';
    my_reverse(str, i);
    return str;
}

void fill_header(target_t *head, header_t **current) // fille my header struct
{
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
    (*current)->name = head->file_name;
    (*current)->mode = mode;
    (*current)->mode[0] = '0';
    (*current)->uid = uid;
    (*current)->gid = gid;
    (*current)->size = size;
    (*current)->mtime = mtime;
    (*current)->next = NULL;
    close(fd);
}

void append_header(target_t *head, header_t **header_file) // append to the header struct
{
    header_t *new = malloc(sizeof(header_t));
    (*header_file)->next = new;
    fill_header(head, &new);
}

header_t *make_header(target_t *head) // make my header struct
{
    header_t *header_file = malloc(sizeof(header_t));
    if (head != NULL)
    {
        fill_header(head, &header_file);
        while (head->next != NULL && header_file != NULL)
        {
            head = head->next;
            append_header(head, &header_file);
        }
    }
    return header_file;
}

void list_archive(archive_t *archive, target_t *target, header_t *header_file)
{
    char *newline = "\n";
    while (header_file != NULL)
    {
        write(1, header_file->name, strlen(header_file->name));
        write(1, newline, 1);
        header_file = header_file->next;
    }
}

void write_archive(archive_t *archive, target_t *target, header_t *header_file)
{
    char *buffer = malloc(BLOCKSIZE);
    buffer[BLOCKSIZE - 1] = '\0';
    memset(buffer, '\0', BLOCKSIZE - 1);
    char *space = " ", *newline = "\n";
    int fout = open(archive->archive_name, O_RDWR, O_CREAT); // open the file;
    while (target != NULL)
    {
        int fd = open(target->file_name, O_RDONLY), readBytes = 0;;
        read(fd, buffer, sizeof(buffer)); // read file to buffer
        write(fout, 1, 1);
        write(fout, header_file->name, strlen(header_file->name));
        write(fout, space, 1);
        write(fout, header_file->mode, strlen(header_file->mode));
        write(fout, header_file->uid, strlen(header_file->uid));
        write(fout, header_file->gid, strlen(header_file->gid));
        write(fout, header_file->size, strlen(header_file->size));
        write(fout, header_file->mtime, strlen(header_file->mtime));
        write(fout, newline, 1);
        write(fout, 2, 1);
        while ((readBytes = read(fd, buffer, BLOCKSIZE)) > 0)
            write(fout, buffer, BLOCKSIZE);
        write(fout, 3, 1);
        close(fd);
        target = target->next;
        header_file = header_file->next;
    }
    memset(buffer, 0, BLOCKSIZE);
    write(fout, buffer, BLOCKSIZE);
    write(fout, buffer, BLOCKSIZE);
    close(fout);
}

void append_Archive(archive_t *archive, target_t *target, header_t *header_file)
{
    int fd = open(target->file_name, O_RDWR);
}

void extract_archive(archive_t* archive)
{
    char *ex_buffer = malloc(BLOCKSIZE);
    header_t* extracted_head = malloc(sizeof(header_t));
    int ex_file =  open(archive->archive_name, O_RDONLY), *i = 0;
    read(ex_file, ex_buffer, sizeof(ex_buffer));
    while(ex_file[i])
    {   
        // extracted_head->name = ex_buffer[0];
        // extracted_head->mode = ex_buffer[1];
        // extracted_head->uid = ex_buffer[2];
        // extracted_head->gid = ex_buffer[3];
        // extracted_head->size = ex_buffer[4];
        // extracted_head->mtime = ex_buffer[5];
        // extracted_head->next = NULL;
        if(ex_file[i] == 2)
        {
            
        }
    }

    
}

int tar_function(target_t *target, arg_t *args, archive_t *archive, header_t *header_file) // tar function to write to file out
{
    char *buffer = malloc(BLOCKSIZE);
    buffer[BLOCKSIZE - 1] = '\0';
    memset(buffer, '\0', BLOCKSIZE - 1);
    if (args->f == true)
    {
        FILE *output_file = fopen(archive->archive_name, "w");
        if (args->c == true)
        {
            write_archive(archive, target, header_file);
        }
        if (args->r == true || args->u == true)
        {
            append_archive(archive, target, header_file);
        }
        if (args->t == true)
        {
            list_archive(archive, target, header_file);
        }
    }
    if (args->x == true)
    {
        // extract the data
        // read data to buffer
        // upto first /0 is name do that 6 times to fill the header struct
        // use the name to create the file
        // upto final something will be the actual data
        // loop though until reach the end with all the /0 stored
        extract_archive(archive);
    }

    return 0;
}
