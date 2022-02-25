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

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif


integer_array* my_count_on_it(string_array* param_1)
{
    integer_array* result;
    int len =  param_1->size;
    result = (integer_array*)malloc(sizeof(integer_array));
    result->size = len;
    result->array = (int *)malloc(sizeof(int *) * result->size);
    
    for (int i = 0;i < len; i++)
    {
       int strLen = strlen(param_1->array[i]);
       result->array[i] = strLen;
    }

    return result;
}

int main(void) {
    char* strArr[] = {"This", "is", "the",};
    string_array arrStruct = {sizeof strArr / sizeof strArr[0], &strArr[0]};

    integer_array* newStructPtr = my_count_on_it(&arrStruct);

    for(int i = 0; i < newStructPtr->size; i++) {
        printf("The length of string %d is: %d\n", i, newStructPtr->array[i]);
    }

    return 0;
}
/*int main(void)
{
    struct s_string_array* string_array = malloc(sizeof(string_array));
       string_array->array = malloc(sizeof(string_array->array));
       string_array->size = 4;
       string_array->array[0] = "abc";
       string_array->array[1] = "efgh";
    integer_array* integer_array = my_count_on_it(string_array);
} */