#include <stdio.h>
#include<string.h>

char reverse_string(char* param_1)
{  
    // declare variable  
    int i, len, temp;  
    len = strlen(param_1); // use strlen() to get the length of str string  
      
    // use for loop to iterate the string   
    for (i = 0; i < len/2; i++)  
    {  
        // temp variable use to temporary hold the string  
        temp = param_1[i];  
        param_1[i] = param_1[len - i - 1];  
        param_1[len - i - 1] = temp;  
    }  
    return *param_1;
}  

int main() {
  char my_str[] = "Hello";
  
  printf("Before reverse -> %s\n", my_str);
  reverse_string(my_str);
  printf("Reverse -> %s\n", my_str);
  return 0;
}