#include <stdio.h>
#include <stdlib.h>
#include "additional.h"
#define MAX_ARRAY_SIZE 128

//this is the main, that pulls the arguments and decides which functions need to be ran
int main(int ac, char **av) {
    int array[MAX_ARRAY_SIZE] = {0, 0, 0, 0};
    int tries = 0;
    if (ac >= 2) {
        for(int j = 0; j < ac; j++) {
           if(my_strcmp(av[j], "-c") == 0){
               for(int i = 0; i < 4; i++) array[i] = av[j+1][i]; }
           if(my_strcmp(av[j], "-t") == 0) {
              tries = atoi(av[j + 1]);
              if(ac < 4){
              int* ans = random_number();
              for(int i = 0; i < 4; i++)
              array[i] = ans[i]; }}
           if(my_strcmp(av[j], "-ct") == 0) {
               for(int i = 0; i < 4; i++) {
                 array[i] = av[j+1][i];}
           tries = atoi(av[j + 2]); } } } 
    else {
        int* ans = random_number();
        for(int i = 0; i < 4; i++) array[i] = ans[i]; }
    repeater(tries, array); }