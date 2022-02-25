#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

void my_print_words_array(string_array* param_1)
{
    int i;
    for (i = 0; i < param_1->size; i++)
    {
        int len = strlen(param_1->array[i]);
        write(1,*(param_1->array[i]), len);
        write(1, "\n", 1);
    }
}

int main()
{
   struct s_string_array* string_array = malloc(sizeof(*string_array));
   string_array-> array = malloc(sizeof(*string_array->array[0]) * 3);
   string_array-> array = malloc(sizeof(*string_array->array[1]) * 3);
   string_array->size = 12;
   string_array->array[0][0] = 'x';
   string_array->array[0][1] = 'x';
   string_array->array[0][2] = 'x';
   string_array->array[1][0] = 'a';
   string_array->array[1][1] = 'b';
   string_array->array[1][2] = 'c';
   printf("Hello\n");
   my_print_words_array(string_array);
   return 0;
}