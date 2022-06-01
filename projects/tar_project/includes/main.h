#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#ifndef MAIN_H
#define MAIN_H

typedef struct s_arg //defining struct for my arguments
{
    bool c;
    bool r;
    bool t;
    bool u;
    bool x;
    bool f;
} arg_t;

typedef struct s_header
{
  char* name; //[100];               /*   0 */
  char* mode; //[8];                 /* 100 */
  char* uid; //[8];                  /* 108 */
  char* gid; //[8];                  /* 116 */
  char* size;//[12];                /* 124 */
  char* mtime;//[12];               /* 136 */
//   char* chksum;//[8];               /* 148 */
//   char* typeflag;                /* 156 */
//   char* linkname;//[100];           /* 157 */
//   char* magic;//[6];                /* 257 */
//   char* version;//[2];              /* 263 */
//   char* uname;//[32];               /* 265 */
//   char* gname;//[32];               /* 297 */
//   char* devmajor;//[8];             /* 329 */
//   char* devminor;//[8];             /* 337 */
//   char* prefix;//[155];             /* 345 */
//                                 /* 500 */
    struct s_header* next;
} header_t;

typedef struct s_targets
{
    char* file_name;
    struct s_targets* next;
} target_t;

typedef struct s_archive
{
    char* archive_name;
} archive_t;

int my_strcmp(char* param_1, char* param_2);
char *int_to_str(unsigned int num, int base);
void listPrinter(target_t* head, arg_t* args, archive_t* archive);
bool parse_function(char* av, arg_t* args, bool* argument_parse);

#endif