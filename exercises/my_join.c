#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif


char* my_join(string_array* param_1, char* param_2)
{
    int len = param_1->size;
    int length = 0;
        for (int n = 0; n < len; n++)
        {
           length += strlen(param_1->array[n]);
        }
    int total = length + (strlen(param_2) * len - 1);
    char* result = malloc(total * sizeof(char));
    int count = 0;
        for (int i = 0; i < len; i++)
        {
            strcat(result, param_1->array[i]);
            if (count != len - 1){
            strcat(result, param_2);
            count++;
            }
            else 
            {
               result[strlen(result)] = '\0';
               return result; 
            }
        }
}

int main(void) 
{
    char* str_arr[] = {"abc", "def", "gh", "!"};
    string_array* arr_struct = malloc(sizeof(string_array)); // {sizeof(str_arr) / sizeof(str_arr[0]), &str_arr[0]};
    arr_struct->size = 4;
    arr_struct->array = str_arr;
    char* dash = "blah";
    char* final = my_join(arr_struct, dash);

    printf("This is the result of main: %s\n", final);

    return 0;
}