#include <stdio.h>
#include <stdlib.h>
#define get(x) #x

int my_strlen(char* param_1)
{
   //printf("%s", param_1);
   int len = 0;

   for (int i = 0; param_1[i]; i++) 
       len++;
       
   return len;
}

char* capital(char* string, int len)
{
    //printf("String Length = %d\n", my_strlen(string) + 1);
    char* output = malloc(sizeof(char) * len);
    for(int i = 0; i < len; i++)
    {
        output[i] = string[i];
        if((string[i + 1] == 32 || string[i + 1] == '\0'))
            output[i] = string[i] - 32;
        if((string[i + 1] == 32 && string[i] == 32))
            output[i] = string[i];
        //printf("capitols = %c index = %d\n", output[i], i);
    }
    //printf("result of capital = %s\n", output);
    return output;
}

char* rcapitalize(char* string)
{
    int length = my_strlen(string) + 1;
    char* new_string = malloc(sizeof(char) * length);

    for(int i = 0; i < length; i++)
    {
        if(string[i] >= 65 && string[i] <= 89)   new_string[i] = string[i] + 32;
        else  new_string[i] = string[i];

    }
    //printf("new_string = %s\n", new_string);
    char* stringo = capital(new_string, length);
    free(new_string);
    stringo[my_strlen(stringo)] = '\0';
return get(stringo);
}

int main(void)
{
    char* str0 = "a FiRSt LiTTlE TESt";
    char* str1 = "SecONd teST A LITtle BiT   Moar comPLEX";
    char* str2 = "   But... This iS not THAT COMPLEX";
    // char* string = rcapitalize(str0);
    // printf("Output = %s\n", string);
    //printf(" string 1 = %s\nwith caps = %s\n", str0, rcapitalize(str0));
    //printf(" string 2 = %s\nwith caps = %s\n", str1, rcapitalize(str1));
    printf(" string 3 = %s\nwith caps = %s\n", str2, rcapitalize(str2));
}