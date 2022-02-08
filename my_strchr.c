#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* my_strchr(char* param_1, char param_2)
{
   do
   {
      if (*param_1==param_2)
        return param_1;
   } while (*param_1++);
   return 0;
}
   

int main() {
  char str[] = "abcbc";
    
  printf("my_strchr -> %s\n", my_strchr(str, 'b'));
   return 0;
}