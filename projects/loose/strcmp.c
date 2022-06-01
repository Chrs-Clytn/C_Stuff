#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("result - %i\n", strcmp(".", ".."));
    printf("result - %i\n", strcmp("..", ".git"));
    printf("result - %i\n", strcmp(".git", "README.md"));


    // string comp - if arg1 is greater than arg 2 (a > R) = 1
    // if arg1 is less than arg2 (R < a) = -1

}