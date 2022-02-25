#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* my_strncpy(char* param_1, char* param_2, int param_3)
{
  size_t i;
  for (i = 0; i < param_3 && param_2[i] != '\0'; i++)
  {
      param_1[i] = param_2[i];
  }
  while (i < param_3)
  {
      param_1[i++] = '\0';
  }
   return param_1;
}

int main() {
  char dst[100] = {0};
  char *src     = "Hello";
  
  printf("my_stnrcpy -> %s\n", my_strncpy(dst, src, 3));
   return 0;
}