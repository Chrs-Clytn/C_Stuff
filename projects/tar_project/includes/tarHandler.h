#include "main.h"
#include "parser.h"
#define BLOCKSIZE 512

#ifndef TARHANDLER_H
#define TARHANDLER_H

char *int_to_str(unsigned int num, int base);
header_t* make_header(target_t *head);
int tar_function(target_t* target, arg_t* args, archive_t* archive, header_t* header_file);

#endif