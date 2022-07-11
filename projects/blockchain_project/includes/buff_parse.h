#ifndef BUFF_PARSE_H
#define BUFF_PARSE_H

// typedef struct buffer_s
// {
//     char* token;
//     struct buffer_t* next;
// } buffer_t;

int parse_buffer(char* buffer, node_t* node_head, block_t* block_head);

#endif