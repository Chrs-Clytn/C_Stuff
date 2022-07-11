#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_ARRAY_SIZE 128

void fill_array(int *array, char *str){
    for(int i = 0; str[i] != '\0'; i++)
        if(str[i] != '"') array[(int)str[i]] += 1;
            //printf("%c: %d\n", str[i], str[i]);
}

void print_array(int *array, int array_size){
    for(int i = 0; i < array_size; i++) 
        if(array[i] > 0) printf("%c:%d\n", i, array[i]);
    return;
}

int main(int ac, char **av){
    int array[MAX_ARRAY_SIZE] = {0};

    for(int i = 1; i < ac; i++ ) fill_array(&array[0], av[i]);
    print_array(&array[0], MAX_ARRAY_SIZE);

    return 0;
}
