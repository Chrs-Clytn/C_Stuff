#include <stdio.h>
#include <unistd.h>

void my_putstr(char* param_1)
{
    //char temp = *param_1;
    //printf("%c", temp);

    //int len = 0;

    for (int i = 0; param_1[i]; i++) 
    {
       //len++;
       //printf("%c", param_1[i]);
        write(1, &param_1[i], 1);
    }

}

int main() {
    my_putstr("abcd");
    return 0;
}