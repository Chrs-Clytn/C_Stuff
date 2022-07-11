#include <stdio.h>

int my_iterative_factorial(int param_1)
{
    if(param_1 > 0)
    {
        int base = 1;
        for(int i = 1; i <= param_1; i++)
        {
            printf("loop no - %d\n", i);
            base = base * i;        
        }
        return base;
    }
    else return 0;
}

int main(void)
{
    int input = 4;
    printf("%d\n", my_iterative_factorial(input));
}