#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* make_one_string(char* param_1, char* param_2)
{
    int len_1 = strlen(param_1) + 1;
    int len_2 = strlen(param_2) + 1;

    printf("Lengths = %d %d \n", len_1, len_2);
    char* new_str = malloc(sizeof(char) * len_1 + len_2);
    strcat(new_str, param_1);
    strcat(new_str, param_2);

    return new_str;
}

int main(void)
{
    char* str1 = "zpadinton";
    char* str2 = "paqefwtdjetyiytjneytjoeyjnejeyj";
    printf("%s\n", make_one_string(str1, str2));
}