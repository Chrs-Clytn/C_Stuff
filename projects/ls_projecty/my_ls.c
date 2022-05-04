#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include "additional.h"

//whats left, 
//figure out how to sort the list
//figure out memory leak

int dirFunction(char* searchTerm, int number)
{
    DIR *folder;
    struct dirent *entry;
    struct stat filestat;
    node *head = (node *)malloc(sizeof(node));
    head->next = NULL;
    folder = opendir(searchTerm);

    if(folder == NULL)
    {
        printf("Unable to read directory");
        return(1);
    }

    while( (entry=readdir(folder)) )
    {   
        printf("debug 1\n");
        stat(entry->d_name,&filestat);
        char* ptr_time = ctime(&filestat.st_mtime);
        append(head, entry->d_name, ptr_time);
    }
    closedir(folder);
    printf("debug 5\n");
    printerFunction(head, number);
    return 0;
}

int main(int ac, char **av)
{
    char *searchTerm; // = malloc(sizeof(char*) * 4);
    int count = 0;
    if (ac >= 3)
    {
        for(int j = 0; j < ac; j++)
        {
           if(my_strcmp(av[j], "-a") == 0)
                count = count + 2;
           if(my_strcmp(av[j], "-t") == 0)
               count = count + 5;
        }
        if(ac == 3)
            searchTerm = av[2];
        if(ac == 4)
            searchTerm = av[3];
    } 
    else
        searchTerm = av[1];
    //printf("debug 0\n");
    dirFunction(searchTerm, count);
    //free(searchTerm);
}