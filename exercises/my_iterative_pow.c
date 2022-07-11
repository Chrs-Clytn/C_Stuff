#include <stdio.h>

int my_iterative_pow(int base, int power)
{
    int result = base;

    for(int i = 1; i < power; i++)
    result *= base;

    return result;
}


int main(void)
{
    printf("%d\n", my_iterative_pow(2, 4));

}