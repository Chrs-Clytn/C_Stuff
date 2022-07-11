#include <stdio.h>>
#include "my_string.h"

int my_strlen(char* param_1)
{
   int len = 0;
   for (int i = 0; param_1[i]; i++) 
       len++;      
   return len;
}

char* my_strchr(char* param_1, char param_2)
{
   do
   {
      if (*param_1==param_2)
        return param_1;
   } while (*param_1++);
   return 0;
}

char* my_strncpy(char* param_1, char* param_2, int param_3)
{
  int i;
  for (i = 0; i < param_3 && param_2[i] != '\0'; i++)
      param_1[i] = param_2[i];
  while (i < param_3)
      param_1[i++] = '\0';
   return param_1;
}

char* my_strcpy(char* param_1, char* param_2)
{
    char *temp = param_1;
    for(size_t i =  0; i < strlen(param_2) + 1; i++)
    {
        param_1[i] = param_2[i];
    }
    param_1 = "\0";
    return temp;
}

char* my_strdup(char* param_1)
{
    char* ptr;
	int len = my_strlen(param_1) + 1;
	ptr = malloc(len);
	if(ptr == NULL)
		return (NULL);
	ptr = my_strcpy(ptr, param_1);
	ptr[len - 1] = '\0';
	return (ptr);
}

char *my_strcat(char *param_1, char *param_2)
{
  int j = 0;
  int i = 0;
  while (param_1[i])
      i++;
  while (param_2[j])
    {
      param_1[i] = param_2[j];
      i++;
      j++;
    }
  param_1[i] = '\0';
  return param_1;
}

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