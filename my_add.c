#include <stdio.h>
#include <unistd.h>

int my_add(int param_1, int param_2)
{
   int tot;
   tot = param_1 + param_2;
   return tot;
}


int main() {
    my_add(0, 1);
    //return ;
}