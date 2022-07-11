#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* my_strip(char* string)
{
    int i, j;
    int len = strlen(string);
    for(i = 0; i < len; i++)
    {
        if(string[0]==' ')
        {
            for(i = 0; i < (len - 1); i++)
            string[i] = string[i+1];
            string[i] = '\0';
            len--;
            i = -1;
            continue;
        }
        if(string[i] == ' ' && (string[i + 1] == ' ' || string[i + 1] == '\0')) // string[i + 1] == '.' || 
        {
            for(j = i; j < (len-1); j++)
            {
                string[j] = string[j + 1];
            }
            string[j] = '\0';
            len--;
            i--;
        }
    }
return string;
}

int main(void)
{
    char* str = "No  S***    Sherlock...";
    printf("%s\n", my_strip(str));
}