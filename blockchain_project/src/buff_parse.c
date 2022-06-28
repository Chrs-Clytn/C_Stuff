#include "main.h"
#include "link_list.h"
#include "buff_parse.h"

// buffer_t *append_buff(buffer_t *head, char* token)
// {
//     if (head == NULL)
//     {
//         buffer_t *head = (buffer_t *)malloc(sizeof(buffer_t));
//         head->token = token;
//         head->next = NULL;
//         return head;
//     }

//     buffer_t *current = head;
//     while (current->next != NULL)
//     {
//         current = current->next;
//     }

//     buffer_t *new = (buffer_t *)malloc(sizeof(buffer_t));
//     new->next = NULL;
//     new->token = token;
//     current->next = new;

//     return head;
// };

void print_list(node_t* header) // test function to print a list
{
    while(header != NULL)
    {
        printf("nid = %d\n", header->nid);
        header = header->next;
    }
}

void print_block(block_t* header) // test function to print a list
{
    while(header != NULL)
    {
        printf("name = %s\n", header->bid);
        header = header->next;
    }
}
// Trying to figure out the best way to add a block.
// also might be a better way to seperate append and creating first node of linked list rather than currently just creating an empty one
//need to figure out my node linked list aswell. doestn seem to be storing
int parse_buffer(char *buffer, node_t *node_head, block_t *block_head)
{
    char *string = buffer, *delim = " ";
    unsigned count = 0;
    bool first_block = true;
    /* First call to strtok should be done with string and delimiter as first and second parameter*/
    char *token = strtok(string, delim);
    count++;
    if (my_strcmp("add", token) == 0)
    {
        token = strtok(NULL, delim);
        if (my_strcmp("node", token) == 0)
        {
            token = strtok(NULL, delim);
            int nid = atoi(token);
            append_node(node_head, nid);
            // printf("added node id = %s\n", token);
            print_list(node_head);
        }
        else if (my_strcmp("block", token) == 0)
        {
            char *block_id = strtok(NULL, delim);
            char *node_id = strtok(NULL, delim);
            int nid = atoi(node_id);
            bool added = false;
            // printf("block id = %s, node id = %s\n", block_id, node_id);
            // if (node_head->nid == nid)
            // {
            //     append_block(block_head, block_id);
            //     added = true;
            //     printf("Added block id = %s, to node id = %s\n", block_id, node_id);
            // }
            // else
                while (node_head->nid != nid && node_head->next != NULL)
                {
                    printf("Node ID = %d\n", node_head->nid);
                    if (node_head->nid == nid)
                    {
                        append_block(block_head, block_id);
                        added = true;
                        // printf("Added block id = %s, to node id = %s\n", block_id, node_id);
                        print_block(block_head);
                    }
                    else
                        node_head = node_head->next;
                }
            if (added == false)
                printf("Error!\n");
            // printf("Node ID = %d\n", node_head->nid);
        }
    }
    return 0;
}
// buffer_t *head = append_buff(NULL, token);
/* Consecutive calls to the strtok should be with first parameter as NULL and second parameter as delimiter
 * * return value of the strtok will be the split string based on delimiter*/
// while (token != NULL)
// {

//     printf("Token no. %d : %s \n", count, token);
//     token = strtok(NULL, delim);
//     count++;
//     // append_buff(head, token);
// }

// for(int i = 0; i < my_strlen(buffer); i++)
// {
//     printf("buffer %i = %s\n", i, );
// }
// return 0;
// }