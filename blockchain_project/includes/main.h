#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#ifndef MAIN_H
#define MAIN_H
#define PROMPT_SIZE 512

typedef struct block_s
{
    char *bid;
    struct block_s *next;
} block_t;

typedef struct node_s
{
    int nid;
    struct block_s *head;
    struct node_s *next;
} node_t;

#endif