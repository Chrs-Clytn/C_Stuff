#include <stdio.h>

int my_strcmp(char* param_1, char* param_2) //my string compare function
{
    while(( *param_1 != '\0' && *param_2 != '\0' ) && *param_1 == *param_2)
    {
        param_1++;
        param_2++;
    }
    if(*param_1 == *param_2)
        return 0; 
    else if(*param_1 < *param_2)
        return -1;
    else
        return 1;
}


int main() 
{
  char *s1 = "Hello";
  char *s2 = "Hgllf";
  
  printf("my_strcmp -> %d\n", my_strcmp(s1, s2));
  return 0;
}