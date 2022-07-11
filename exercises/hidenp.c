#include <stdio.h>
#include <string.h>

int hidenp(char* str0, char* str1)
{
    int len1 = strlen(str0) + 1, len2 = strlen(str1) + 1, i, j;
    int count = 0;
    for(i = 0; i < len1;i++)
    {
        for(j = 0; j < len2; j++)
        {
            if(str0[i] == str1[j])
            {
                count++;
                if(count > 0)
                i++;
            }

        }
    }
    if(count == len1)
    return 1;
return 0;
}

int main()
{
    char* str0 = "abc";
    char* str1 = "btarc";
    printf("Return = %d\n", hidenp(str0, str1));
}