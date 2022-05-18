#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "additional.h"

// whats left, 
// figure out time 
// 

int dirFunction(char* searchTerm, arg_t* args) //directory function, opens and reads directory, stats the information required.
{
    DIR *folder;
    struct dirent *entry;
    struct stat filestat;
    node *head = (node *)malloc(sizeof(node));
    head->name = NULL;
    //head->time = NULL;
    head->next = NULL;
    folder = opendir(searchTerm);
    if(folder == NULL)
    {
        printf("Unable to read directory\n");
        return(1);
    }
    while( (entry=readdir(folder)) )
    {   
        char test[50];
        strcpy(test, searchTerm);
        strcat(test, "/");
        lstat(strcat(test, entry->d_name), &filestat);
        append(head, entry->d_name, filestat.st_mtime);
    }  
    printerFunction(head, args);
    closedir(folder);
    free(head);
    return 0;
}

int main(int ac, char **av) //main function takes the arguments and parses them to either search term or arg struct
{
    char *searchTerm = ".";
    arg_t* args = (arg_t *)malloc(sizeof(arg_t));
    args->a = false;
    args->b = false;
    for(int j = 0; j < ac; j++)
    {
        if(my_strcmp(av[j], "-a") == 0)
            args->a = true;
        if(my_strcmp(av[j], "-t") == 0)
            args->b = true;
        if((my_strcmp(av[j], "-t") != 0) && (my_strcmp(av[j], "-a") != 0) && (my_strcmp(av[j], "./my_ls") != 0))
            searchTerm = av[j];
    }
    //printf("searchterm = %s, ac = %i \n", searchTerm, ac);
    dirFunction(searchTerm, args);
}