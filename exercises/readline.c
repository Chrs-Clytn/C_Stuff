#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

int READLINE_READ_SIZE;
char *STORAGE;

int my_strlen(char *param_1)
{
    int len = 0;
    for (int i = 0; param_1[i]; i++)
        len++;
    return len;
}

char *my_strchr(char *param_1, char param_2)
{
    do
    {
        if (*param_1 == param_2)
            return param_1;
    } while (*param_1++);
    return 0;
}

char *my_strncpy(char *param_1, char *param_2, int param_3)
{
    for (int i = 0; i < param_3 && param_2[i] != '\0'; i++)
    {
        param_1[i] = param_2[i];
        while (i < param_3)
            param_1[i++] = '\0';
    }
    return param_1;
}

char *my_strcpy(char *param_1, char *param_2)
{
    char *temp = param_1;
    while (*param_2 != '\0')
    {
        temp = param_2;
        param_1++;
        param_2++;
    }
    param_1 = '\0';
    return temp;
}

char *my_strdup(char *param_1)
{
    char *ptr;
    int len = my_strlen(param_1) + 1;
    ptr = malloc(len);
    if (ptr == NULL)
        return (NULL);
    ptr = my_strcpy(ptr, param_1);
    ptr[len - 1] = '\0';
    return (ptr);
}

char *my_strcat(char *param_1, char *param_2)
{
    int j = 0;
    int i = 0;
    while (param_1[i])
        i++;
    while (param_2[j])
    {
        param_1[i] = param_2[j];
        i++;
        j++;
    }
    param_1[i] = '\0';
    return param_1;
}

char *my_readline(int fd)
{
    char buffer[READLINE_READ_SIZE + 1];
    int readBytes;
    char *tmp = NULL;
    char *currBuffer = NULL;
    char *ret = NULL;
    char *ptr = NULL;
    char *blankline = NULL;

    if (STORAGE) // something in storage
    {
        if ((tmp = my_strchr(STORAGE, '\n'))) // and full line
        {
            ret = malloc(sizeof(char) * my_strlen(STORAGE) - my_strlen(tmp) + 1);
            my_strncpy(ret, STORAGE, my_strlen(STORAGE) - my_strlen(tmp) + 1);

            blankline = malloc(sizeof(char) * my_strlen(STORAGE) - my_strlen(tmp) + 1);
            my_strcpy(blankline, tmp + 1);
            my_strcpy(STORAGE, blankline);

            free(STORAGE);
            STORAGE = my_strdup(tmp + 1); // shorten storage and return
            return ret;
        }
        else // if there is something but not a full line
        {
            currBuffer = my_strdup(STORAGE); // append to the next read buffer
            free(STORAGE);
            STORAGE = NULL;
        }
    }

    while ((readBytes = read(fd, buffer, READLINE_READ_SIZE)) > 0) // need to check whether there is an \n in the string, if there is not break the if statement and continue loop, if there is store the remaining charaters in storage
    {
        buffer[readBytes] = '\0'; // set last line of buffer to terminating 0.
        if (currBuffer)           // append Buffer
        {
            tmp = malloc(sizeof(char) * my_strlen(currBuffer) + my_strlen(buffer) + 1);
            my_strcpy(tmp, currBuffer);
            my_strcat(tmp, buffer);
            //free(currBuffer);
            currBuffer = my_strdup(tmp);
            free(tmp);
            tmp = NULL;
        }
        else
            currBuffer = my_strdup(buffer);

        if ((ret = my_strchr(currBuffer, '\n')))
        {
            tmp = malloc(my_strlen(currBuffer) - my_strlen(ret) + 1);
            my_strncpy(tmp, currBuffer, my_strlen(currBuffer) - my_strlen(ret) + 1);
            STORAGE = my_strdup(ret + 1);
            ptr = strtok(tmp, "\n");
            free(tmp);
            tmp = NULL;
            return ptr;
        }
    }
    return currBuffer;
}

void init_my_readline(int value)
{
    READLINE_READ_SIZE = value;
}

int main(int ac, char **av)
{
    int value = 5;
    char *line;
    char *file;
    for (int i = 0; i < ac; i++)
    {
        printf("av%d = %s\n",i, av[i]);
        if (av[1])
            file = av[1];
    }
    printf("file = %s\n", file);
    init_my_readline(value);
    STORAGE = malloc(sizeof(READLINE_READ_SIZE));
    int fd = open(file, O_RDONLY);
    while ((line = my_readline(fd)))
        printf("result = %s\n", line);
    return 0;
}