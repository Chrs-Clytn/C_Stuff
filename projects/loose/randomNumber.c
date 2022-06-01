#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#define MAX_ARRAY_SIZE 128


int* main()
{
    int n =4, i;
    int rando[MAX_ARRAY_SIZE] = {0, 0, 0, 0};
    bool arr[4];
    srand(time(0));
    for(i = 0; i < 4; i++)
    {
       int r = 48 + rand()%7;
       if(!arr[r])
          rando[i] = r;
       else
          i--;
       arr[r]=1;
    }
    printf("%ls\n", rando);
    int *ptr = rando;
    return ptr;
}


