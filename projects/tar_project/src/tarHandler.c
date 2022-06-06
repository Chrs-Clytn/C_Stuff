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
        //printf("start of while loop\n");
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
        //printf("end of while loop\n");
    }
    if (isNegative){
        str[i++] = '-';
    }
    str[i] = '\0';
    my_reverse(str, i);
    //printf("itoa str = %s\n", str);
    return str;
}
void fill_header(target_t *head, header_t *current)
{
    //printf("start of fill header\n");
    //header_t *current = header_file;
    struct stat filestat;
    int fd = open(head->file_name, O_RDONLY);
    fstat(fd, &filestat); // do some filestat stuff...
    char *name = head->file_name;
    char mode[8];
    char uid[8];
    char gid[8];
    char size[12];
    char mtime[12];
    my_itoa_base(filestat.st_mode, mode, 8);
    my_itoa_base(filestat.st_uid, uid, 8);
    my_itoa_base(filestat.st_gid, gid, 8);
    my_itoa_base(filestat.st_size, size, 8);
    my_itoa_base(filestat.st_mtime, mtime, 8);
    //printf("mode = %d, uid = %d, gid = %d, size = %ld, mtime = %ld\n", filestat.st_mode, filestat.st_uid, filestat.st_gid, filestat.st_size, filestat.st_mtime);
    //current->name = head->file_name;
    current->name = head->file_name;
    current->mode = mode;
    current->uid = uid;
    current->gid = gid;
    current->size = size;
    current->mtime = mtime;
    //header_file->next = NULL;
    current->next = NULL;
    close(fd);
}

void append_header(target_t *head, header_t* header_file) //function to make the header
{
    //printf("start of append header\n");
    header_t *new = malloc(sizeof(header_t));
    header_file->next = new;
    fill_header(head, new);
    //print_list(header_file);
}

header_t *make_header(target_t *head)
{
    // printf("start of make header\n");
    header_t *header_file = malloc(sizeof(header_t));
    if (head != NULL)
    {
        fill_header(head, header_file);
        //print_list(header_file);
        while (head->next != NULL && header_file != NULL)
        {
            //printf("if statement\n");
            //printf("start of while loop in make header\n");
            head = head->next;
            //printf("file name = %s\n", head->file_name);
            append_header(head, header_file);
            print_list(header_file);
        }
    }
    //print_list(header_file);
    return header_file;
}

//need to fix the header file information.
// void make_header(target_t *head, header_t* header_file) //function to make the header
// {
//     while(head != NULL)
//     {
//         //printf("start of while loop\n");
//         struct stat filestat;
//         int fd = open(head->file_name, O_RDONLY);
//         fstat(fd, &filestat); // do some filestat stuff...
//         char* name = head->file_name;
//         char mode[8]; 
//         char uid[8];
//         char gid[8];
//         char size[12];
//         char mtime[12];
//         printf("mode = %d, uid = %d, gid = %d, size = %ld, mtime = %ld\n", filestat.st_mode, filestat.st_uid, filestat.st_gid, filestat.st_size, filestat.st_mtime);
//         my_itoa_base(filestat.st_mode, mode, 8);
//         my_itoa_base(filestat.st_uid, uid, 8);
//         my_itoa_base(filestat.st_gid, gid, 8);
//         my_itoa_base(filestat.st_size, size, 8);
//         my_itoa_base(filestat.st_mtime, mtime, 8);
//         //printf("middle of while loop\n");
//         header_t *current = header_file;
//         while (current->next != NULL)
//             current = current->next;
//         header_t *new = malloc(sizeof(header_t));
//         new->name = head->file_name;
//         new->name = head->file_name;
//         new->mode = mode;
//         new->uid = uid;
//         new->gid = gid;
//         new->size = size;
//         new->mtime = mtime;
//         new->next = NULL;
//         new->next = NULL;
//         current->next = new;
//         close(fd);
//         if(head->next != NULL)
//             head = head->next;
//         else
//             break;
//         //printf("wnd of while loop\n");
//     }
//     print_list(header_file);
// }

int tar_function(target_t* target, arg_t* args, archive_t* archive, header_t* header_file) //tar function to write to file out
{
    FILE* output_file = fopen(archive->archive_name, "w");
    //char* output_file = archive->archive_name;
    char buffer[512];
    int fout = open(archive->archive_name, O_RDWR, O_CREAT); // open the file;
    //printf("size of buffer =  %ld\n", sizeof(buffer));
    if (args->c == true && args->f == true)
    {
        while (target != NULL)
        {
            int fd = open(target->file_name, O_RDONLY);
            read(fd, buffer, sizeof(buffer));               // read file to buffer 
            write(fout, header_file, sizeof(header_t));
            write(fout, buffer, (sizeof(buffer) + 1));      // write buffer to fileout stored in args
            target = target->next;
            //write(1, buffer, (sizeof(buffer) + 1));
        }
    }
    //write(1, header_file, sizeof(header_t));
    //printf("buffer = %s\n", buffer);
    //printf("file out %s\n", fout);
    return 0;
}
