#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char param_1;

int my_isalpha(char param_1) {
char alfabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
for ( int i = 0; i < sizeof(alfabet); i++ )
if ( alfabet[i] == param_1 ) {
return 1;
}
else return 0;
};

void main() {
    char x ;
    printf("Please enter a character");
    scanf("%c", x);
    x = param_1;
my_isalpha(param_1);
}