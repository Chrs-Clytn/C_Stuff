// Blockchain:
// struct
// linked list
// each node has some blocks in it
// each block is one single transaction
// define structures for the blocks and for the nodes
// create functions that power the commands
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// create main function to read the prompt to buffer
    // this should consist of a loop to read the prompt
    // should print out the prompt each loop
    // print out either "s" or "-" whether synchronised or not. and the number of nodes surrounded by brackets with > e.g. [s1]>
    // for this last bit i need to add functions to count the number of nodes in the list, and to compare the contents of the blocks on each node to see if synchronised
// create function to append to the node struct 
    // take node id from prompt and create a node with that id
    // need to figure out a better way of creating the first node
// create function to append to the block struct and to a specific node
        // take node id add block struct to that node id
        // take block id from prompt and create a block with that id
        // if nid = "*" block is added to all nodes
// create function to remove nodes 
    // remove node based on nid
    // if nid = "*" all nodes are removed
// create function to remove blocks
    // remove block based on bid
// create function to list the node identifiers
    // print out nid and "\n"
    // if option -l print out nid followed by ":" space and then bid followed by "," until bid = NULL then "\n"
// create a sync function to copy all blocks to each node
    // iterate through nodes and find one with the most blocks
    // copy those blocks to each other node
// add quit to the intial loop inside the main

// NID is int BID is string

// #define PROMPT_SIZE 512;
#include "main.h"
#include "link_list.h"
#include "buff_parse.h"

int main(void)
{
    block_t *block_head = (block_t *)malloc(sizeof(block_t));
    node_t *node_head = (node_t *)malloc(sizeof(node_t));
    char *buffer = malloc(sizeof(char) * PROMPT_SIZE), *sync_state = "s", *node_number = "0";
    //bool first_node = true;
    do
    {
        write(1, "[", 1);
        write(1, sync_state, 1);
        write(1, node_number, 1);
        write(1, "]", 1);
        write(1, ">", 1);
        read(0, buffer, PROMPT_SIZE);
        buffer[my_strlen(buffer)] = '\0';
        parse_buffer(buffer, node_head, block_head);
    } while (my_strcmp(buffer, "quit") != 0);

    // if(check_sync() == 1)
    //     sync_state = '-';
    // else
    //     sync_state = 's';
    // node_number = check_node_number();

    return 0;
}