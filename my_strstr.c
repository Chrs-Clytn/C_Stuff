#include <stdio.h>
#include <string.h>

char* my_strstr(char* param_1, char* param_2)
{ 
    int i = 0;
    int j = 0;
    int n;

    if (!param_2 || *param_2 == '\0') //Check if it exists and if its empty.
       return param_1;
       
    while (param_1[i])
    {
        n = i;
        while (param_2[j])
        {  
           if (param_1[n] != param_2[j])
               break;
           n++;
           j++;
        }
           if (param_2[j] == '\0')
           {
              return &param_1[i];
           }
        i++;
        j = 0;
    }
    return NULL;
}

int main(void) {
  char str[] = "mississipi";
  char str2[] = "si";
  
  printf("string appears %s, ", my_strstr(str, str2));
   return 0;
}