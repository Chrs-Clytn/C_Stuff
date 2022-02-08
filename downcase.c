#include <stdio.h>
#include <string.h>

char* my_downcase(char* param_1)
{
    for (int i = 0; param_1[i]; i++) 
    {
        if (param_1[i] >= 65 && param_1[i] < 91)
        {
           param_1[i] += 32;
        }
    }
    return param_1;
    printf("%s", param_1);
}

int main() {
  char *my_str = strdup("AbcE Fgef1");
  
  printf("RANDOM CASE -> %s\n", my_str);
  printf("UPCASE      -> %s\n", my_downcase(my_str));
  return 0;
}