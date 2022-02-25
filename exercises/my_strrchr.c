#include <stdio.h>
#include <string.h>

char* my_strrchr(char* param_1, char param_2)
{
   int i = strlen(param_1);

   for (i > 0; i--;)
   {
       if (param_1[i] == param_2)
       {
           return &param_1[i];
       }
   }
}

int main() {
  char str[] = "abcbc";
    
  printf("my_strrchr -> %s\n", my_strrchr(str, 'b'));
   return 0;
}