#include <stdio.h>
#include <string.h>

char* my_upcase(char* param_1)
{
    // There will need to be a loop.
    for (int i = 0; param_1[i]; i++) 
    {
    //I want to use ascii to differentiate, so maybe if the number is greater than or equal to 97 i can just deduct 32
        if (param_1[i] >= 97 && param_1[i] < 123)
        {
           param_1[i] -= 32;
        }
    }
    return param_1;
    printf("%s", param_1);
}

int main() {
  char *my_str = strdup("AbcE Fgef1");
  
  printf("RANDOM CASE -> %s\n", my_str);
  printf("UPCASE      -> %s\n", my_upcase(my_str));
  return 0;
}