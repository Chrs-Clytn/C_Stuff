#include <stdio.h>
#include <string.h>

char* last_word(char* param_1)
{
   int i = strlen(param_1) - 1;
   printf("strlen = %d, param_1 = %s \n", i, param_1);
   if (i <= 0)
     return param_1;
   for (i > 0; i--;)
   {
       if ((param_1[i] == ' ' && param_1[i - 1] != ' ' && param_1[i+1] != ' ') || param_1[i] == ',')
       {
           return &param_1[i + 1];
       }
   }
}

void main()
{
char str0[] = "FOR PONIES";
char str1[] = "  lorem,ipsum  ";
char str3[] = "";

printf("%s\n", last_word(str0));
printf("%s\n", last_word(str1));
printf("%s\n", last_word(str3));
return;
}