#include <stdio.h>
#include <unistd.h>

void my_print_alphabet()
/*{
    char c;
    for (c = 'a'; c <= 'z'; ++c)
    printf("%c", c);
}*/
{
    //for (int c = 97; c <= 122; c++)
    /*char c;
    int fd;
    for (c = 'a'; c <= 'z'; ++c)
    write(fd, &c, 25);*/

    for (char c = 'a'; c <= 'z'; c++) {
       write(1, &c, 1);

    }
       char c = '\n';
       write(1, &c, 1);
   
}
int main() {
    my_print_alphabet();
}