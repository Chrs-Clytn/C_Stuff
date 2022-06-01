#include "main.h"
#ifndef PARSER_H
#define PARSER_H

void addArchiveName(char* av, archive_t* archive);
target_t* addFile(char* av, target_t* head);
bool parse_function(char* av, arg_t* args, bool* argument_parse);


#endif