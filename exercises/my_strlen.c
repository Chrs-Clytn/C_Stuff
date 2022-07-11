#include <stdio.h>

int my_strlen(char* param_1)
{
   int len = 0;
   for (int i = 0; param_1[i]; i++) 
       len++;      
   return len;
}

int main() {
    my_strlen("abcd");
    return 0;
}