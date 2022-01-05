#include <stdio.h>

int my_isdigit(char param_1)
{
char dig[] = "0123456789";
int x = 0;
//printf("%ld", sizeof(dig));
for (int i = 0; i < 10; i++) {
    printf("%c\t%c\n", dig[i], param_1);
   if (dig[i] == param_1 ) {
      printf("Hello\n");
      return 1;
   }
    /*else {
        printf("world\n");
        x = 0;
     }*/
}
return 0;
}

int main() 
{
    my_isdigit('a');
    return 0;
}
