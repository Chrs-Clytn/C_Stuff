#include <stdio.h>
#include <stdlib.h>

int* my_range(int param_1, int param_2)
{
   int len = param_2 - param_1;
   int *arr =  malloc(len * sizeof(int));
   int max = param_2;
   int min = param_1;
   
   while (min < max)
   {
     int temp = min;
       for (int i = 0; i <= len; i++)
       {
           arr[i] = min;
           min++;
       }
   }
   printf("Array: %ls\n", arr);
   return arr;
}

int main()
{
printf("The range is: %ls\n", my_range('1', '4'));
}