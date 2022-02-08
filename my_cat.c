#include <stdio.h>

// open input file
// read the file ive opened 
// print it out to the terminal
// close the file

char my_cat(param_1, param_2)
{
    char *fptr1 = param_1;
    char *fptr2 = param_2;

    fopen(fptr1, fptr2);
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
    return 0;
    }
    char* fptr1 = argv[1];
    char* fptr2 = argv[2];

  my_square(fptr1, fptr2);
}