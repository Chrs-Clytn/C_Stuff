#include <stdio.h>

int my_recursive_factorial(int fact)
{
    int answer;
    if(fact >= 1)
    {
        answer = fact*my_recursive_factorial(fact - 1);
        return answer;
    }
    else return 1;
}

int main(void)
{
    int input = 3;
    printf("%d\n", my_recursive_factorial(input));
}