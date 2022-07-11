#include <stdio.h>
#include <unistd.h>


int my_string_index(char* param_1, char param_2)
{
    int num = 0;
    for (int i = 0; param_1[i]; i++) 
    {
       if (param_1[i] == param_2) {
         printf("%d\n", num);
         return num;
       }
           num++;
    }
}

char main() 
{   
    my_string_index("hello", 'l');
}