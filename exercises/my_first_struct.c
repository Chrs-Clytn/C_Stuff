#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif

/*
void my_first_struct(integer_array* param_1)
{
   int i = 0;
   int len = param_1->size;
   //len += 1;
   printf("can i just print out the array? %i\n", len);

   printf("size: %i\n", param_1->size);
   //printf("This is the array size. pointer + int: %ld\n", sizeof(param_1->array));
   //printf("This is the length: %ls\n", len);
   //printf("%c\n", param_1);
    if (*param_1->array == '\0')
    {
    printf("0\n");
    }
    while (i <= param_1->size)
    {
        if (param_1->array[i] == '\0')
        break;
        printf("trying to print index of array: %d\n", param_1->array[i]);
        //param_1++;
        i++;
    }
   
} */

void my_first_struct(integer_array* param_1)
{
    int i = 0;
    int len = param_1->size;
    printf("%i\n", len);
    for (; i < len; i++)
    {
        //printf("we make it here %d\n", param_1->array[i]);
        printf("%d\n", param_1->array[i]);
    }
}


int main()

{
    struct s_integer_array* integer_array = malloc(sizeof(*integer_array));

   integer_array-> array = malloc(sizeof(*integer_array->array) * 3);
   
   integer_array->size = 6;
   integer_array->array[0] = 10;
   integer_array->array[1] = 2;
   integer_array->array[2] = 3;
   integer_array->array[3] = 3;
   integer_array->array[4] = 0;
   integer_array->array[5] = -1;
   my_first_struct(integer_array);
   //printf("%ls\n", myNumber.array);
   return 0;
}