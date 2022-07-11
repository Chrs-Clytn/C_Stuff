#include <stdio.h>

int my_atoi(char* string)
{
    int convert;
    int result = 0;
    int negative = 1;

    if(*string == '-')
    negative = -1;
    string++;

    while(*string >= '0' && *string <= '9')
    {
        convert = (*string - '0');
        result = result * 10 + convert;
        string++;
    }
    return negative * result;
}

int main(void)
{
    char* input = "-123";
    printf("%d\n", my_atoi(input));
}