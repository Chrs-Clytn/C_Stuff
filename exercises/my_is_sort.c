#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif


bool my_is_sort(integer_array* param_1)
{
    const int *arr = param_1->array;
    int size = param_1->size;

    if (size <= 1)
        return true;

    int i;

    // true if [still] have ascending sort
    int ascend = 1;

    // true if [still] have descending sort
    int descend = 1;

    // the value of the "previous" array element
    int prev = arr[0];

    // the value of the "current" array element
    int cur;

    for (i = 1;  i < size;  ++i, prev = cur) {
        // get current array value
        cur = arr[i];

        // compare against previous value
        int dif = cur - prev;

        // elements are the same -- no change in status
        if (dif == 0)
            continue;

        // one of the directions has to be out-of-sort
        if (dif < 0)
            ascend = 0;
        else
            descend = 0;

        // early escape -- neither direction is in sort
        if ((ascend | descend) == 0)
            break;
    }

    return (ascend | descend) ? true : false;
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
   my_is_sort(integer_array);
   return 0;
}