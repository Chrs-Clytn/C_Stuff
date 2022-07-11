#include <stdio.h>

int my_fibonacci(int n)
{
    if(n <= 1)
        return n;
    return my_fibonacci(n - 1) + my_fibonacci(n - 2);
}

int main(void)
{
    int input = 3;
    printf("%d\n", my_fibonacci(input));
}