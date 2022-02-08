#include <stdio.h>

int my_strlen(char* param_1)
{
    //char temp = *param_1;
    //printf("%c", temp);
    printf("%s", param_1);
  // char str[50] = {*param_1};
   //printf("%s", str);
   int len = 0;

   for (int i = 0; param_1[i]; i++) 
   {
       len++;
   }
   //printf("%d", len);
   return len;
}

int main() {
    my_strlen("abcd");
    return 0;
}