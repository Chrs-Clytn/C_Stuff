#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#define MAX_ARRAY_SIZE 128
//Simple function to compare 2 strings to make the flags work!
int my_strcmp(char* param_1, char* param_2)
{
    while(( *param_1 != '\0' && *param_2 != '\0' ) && *param_1 == *param_2)
    {
        param_1++;
        param_2++;
    }
    if(*param_1 == *param_2)
        return 0; 
    else
        return 1;
}

// This function generates a random 4 digit number between 0-7 with no duplicates.
int * random_number()
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
    int *ptr = rando;
    return ptr;
}

//This is the function that collates the guess and answer, and then reports back the good and bad counts to the user.
//It actually checks the pieces against all others and reports how many are in the correct place or not
int complete_mastermind(char* guess, int* answer)
{
    printf("Guess : %s, Answer: %ls\n", guess, answer);
    int goodCount = 0;
    int badCount = 0;
        for(int i = 0; i < 4; i++)
        {
            if(guess[i] == answer[i])
            goodCount++;
            if(guess[i] == answer[i+1] || guess[i] == answer[i+2] || guess[i] == answer[i+3])
            badCount++;
            if(guess[i] == answer[i-1] || guess[i] == answer[i-2] || guess[i] == answer[i-3])
            badCount++;
        }
        if(goodCount == 4)
        {
           printf("Congratz! you did it!\n"); 
           return 0;
        }
        if(goodCount < 4)
        {
            printf("Well placed pieces: %d\n", goodCount);
            printf("Misplaced pieces: %d\n ---\n", badCount);
            goodCount = 0;
            badCount = 0;
            return 1;
        }  
}
//This function reads the user input, and reports back if the user has input incorrectly
char * read_input()
{
    char buff[MAX_ARRAY_SIZE];
    read(0, buff, 5);
    if((buff[0] < 47 || buff[0] > 58) || (buff[1] < 47 || buff[1] > 58) || (buff[2] < 47 || buff[2] > 58) || (buff[3] < 47 || buff[3] > 58))
    {
        printf("Wrong input!\n");
        read_input();
    }
  char* ptr = buff;
  return  ptr;
}
//This is my repeater function which takes the tries/answer from main and then runs the rest x number of times.
int repeater(int tries, int* ans)
{
    int repeat = 1;
    int maxTry = 10;
    int n = 0;
    if(tries > 0) maxTry = tries;
    printf("Will you find the secret code?\n ---\n");
    for(int i = 0; i < maxTry;)
    {
        printf("Round %d\n", i);
        char* input = read_input();
        int repeat = complete_mastermind(input, ans);
        if(repeat == 0) return 0;
        if(repeat != 0) 
        {
            i++;
            n++;
        }
        if(n == maxTry)
        {
          printf("Out of Tries!\n");
          n = 0;
          return 0;    
        }
    }
}

//this is the main, that pulls the arguments and decides which functions need to be ran
int main(int ac, char **av)
{
    int array[MAX_ARRAY_SIZE] = {0, 0, 0, 0};
    int tries = 0;
    if (ac >= 2)
    {
        for(int j = 0; j < ac; j++)
        {
           if(my_strcmp(av[j], "-c") == 0)
           {
               for(int i = 0; i < 4; i++)
                   array[i] = av[j+1][i];
           }
           if(my_strcmp(av[j], "-t") == 0)
              tries = atoi(av[j + 1]);
        }
    } 
    else
    {
        int* ans = random_number();
        for(int i = 0; i < 4; i++)
        array[i] = ans[i];
    }
    repeater(tries, array);
}