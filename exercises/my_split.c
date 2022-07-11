#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct string_array
{
    int size;
    char** array;
} string_array;
#endif

int word_count(char* str, char c)
{
    int result = 1;
    for (int i = 0; i < (strlen(str) + 1); i++)
    {
        if(str[i] == c)
        result++;
    }
    printf("word result = %d\n", result);
    return result;
}

string_array* my_split(char* a_str, char* a_delim1)
{
    int words = word_count(a_str, a_delim1[0]);
    string_array* result;
    result = malloc(sizeof(string_array));
    result->size = words;
    result->array = malloc(words * sizeof(char*));
    char a_delim = a_delim1[0];
    //char** result = 0;
    size_t count = 0;
    char* tmp = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;
    printf("we get here, a_delim = %c, *tmp = %s\n", a_delim, tmp);

    /* Count how many elements will be extracted. */
    while (*tmp != '\0')
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
            printf("not here\n");
        }
        tmp++;
        printf("we do get here\n");

        count += last_comma < (a_str + strlen(a_str) - 1);
        count++;
        printf("result = %s\n", result->array[0]);

        if (result)
        {
            size_t idx  = 0;
            char* token = strtok(a_str, delim);
            printf("DO we get here?\n");

            while (token)
            {
                int i = 0;
                assert(idx < count);
                result->array[i] = strdup(token);
                token = strtok(0, delim);
                i++;
            }
        assert(idx == count - 1);
        //result->size = 0;
        }
    }
    printf("result = %s\n", result->array[0]);
    printf("result = %s\n", result->array[1]);

return result;
}

int main(void)
{
    my_split("abc def gh-!", "-");
return 0;
}