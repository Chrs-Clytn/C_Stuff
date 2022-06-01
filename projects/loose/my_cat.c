#include <stdio.h>
#include <stdlib.h>

// open input file
// read the file ive opened 
// print it out to the terminal
// close the file

int main(int argc, char **argv)
{
    FILE* fptr1;
    char line[255];

    FILE* fptr2;
    char buff2[255];

    fptr1 = fopen(argv[1], "r");
        while(fgets(line, sizeof(line), fptr1))
        printf("%s\n", line);

    fclose(fptr1);

    if(argc == 3) 
    {
      fptr2 = fopen(argv[2], "r");
        while(fgets(buff2, sizeof(buff2), fptr2))
        printf("%s\n", buff2);

    fclose(fptr2);
    }
}