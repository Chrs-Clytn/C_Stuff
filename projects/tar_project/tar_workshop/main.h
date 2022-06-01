#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#ifndef MAIN.H
#define MAIN.H

#define PARSING_FAILED -1
#define USEAGE "my_tar is a command to manipulate tape archive. The first option to tar is a mode indicator from the following list:\n -c Create a new archive containing the specified items.\n -r Like -c, but new entries are appended to the archive. The -f option is required.\n -t List archive contents to stdout.\n -u Like -r, but new entries are added only if they have a modification date newer than the corresponding entry in the archive. The -f option is required.\n -x Extract to disk from the archive.\n If a file with the same name appears more than once in the archive, each copy will be extracted, with later copies overwriting (replacing) earlier copies.\n In -c, -r, or -u mode, each specified file or directory is added to the archive in the order specified on the command line. By default, the contents of each directory are also archived. Unless specifically stated otherwise, options are applicable in all operating modes: -f file Read the archive from or write the archive to the specified file. The filename can be standard input or standard output"
#define DEBUG 0

typedef struct s_arg //defining struct for my arguments
{
    bool c;
    bool r;
    bool t;
    bool u;
    bool x;
    bool f;
} arg_t;

enum fileType
{
    FileType,
    FolderType,
};

typedef struct s_largs
{
    char* arg_name;
    enum fileType type;
    struct s_largs *next;
} largs_t;

typedef struct s_data
{
    char* archive_name;
    largs_t* arguments;
    struct arg_t* options;
} data_t;
#endif

