#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int my_string_index(char* param_1, char param_2)
{
    char* output = malloc(sizeof(char) * strlen(param_1));
    for (int i = 0; param_1[i] != '\0'; i++) 
    {
       if (param_1[i] == param_2) 
         return 1;
    }
    return 0;
}

char* my_union(char* param_1, char* param_2)
{
    int len_1 = strlen(param_1) + 1;
    int len_2 = strlen(param_2) + 1;
    char* new_str = malloc(sizeof(char) * len_1 + len_2);
    strcat(new_str, param_1);
    strcat(new_str, param_2);
    int new_len = strlen(new_str) + 1;
    int i, j, k;

    for(i = 0; i < new_len; i++)
    {
        if(my_string_index(new_str, new_str[i]) == 1)
        new_str[i] = 0;
    }
    return new_str;
}

int main(void)
{
    char* str1 = "zpadinton";
    char* str2 = "paqefwtdjetyiytjneytjoeyjnejeyj";
    printf("%s\n", my_union(str1, str2));
}