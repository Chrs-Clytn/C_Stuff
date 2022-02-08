#include <stdio.h>

char* my_strcpy(char* param_1, char* param_2)
{
    char *temp = param_1;
    while (*param_2 != '\0')
    {
      *param_1 = *param_2;
      *param_1++;
      *param_2++;
    }
    param_1 = '\0';
    return temp;
}

int main() {
  char dst[100] = {0};
  char *src     = "Hello";
  printf("my_strcpy -> %s\n", my_strcpy(dst, src));
  return 0;
}