#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

// Do the same as union, but only upto max length og first string
//Possibly take the first letter of the first string and then compare it to each letter in the second string to see whether it appears.
//if it appears in the second string, add it to a new string
//then loop through union again to remove any duplicates

char second_string(char* string, char c)
{
    //printf("String = %s\n", string);
    int i = 0, len = strlen(string);
    for (i = 0; i < strlen(string); i++) 
    {
        //printf("string = %c, c = %c\n", string[i], c);
        if (string[i] == c) 
        {
           //printf("its a match, string index = %c\n", string[i]);
           return string[i];
        }  
    }
    return 94; 
}

char* inter(char* param_1, char* param_2)
{
    //printf("Param 1 = %s\n", param_1);
    int i, j, k, len = strlen(param_2);
    char* output = malloc(sizeof(char) * strlen(param_1)); // + strlen(param_2));
    //char last = param_2[strlen(param_2)-1];
    //printf("last = %c\n", last);
    for(i = 0; i < strlen(param_1); i++)
    {
        char x = second_string(param_2, param_1[i]);
        //if(x != 94)
        output[i] = x;
    }
    // printf("result of second string %s\n", output);
    for (i = 0; i < strlen(output); i++)
  	{
  		for(j = i + 1; output[j] != '\0'; j++)
  		{
  			if(output[j] == output[i] || output[j] == 94)  
			{
  				for(k = j; output[k] != '\0'; k++)
				{
                    //printf("New string K = %c and k++ = %c\n", output[k], output[k+1]);
					output[k] = output[k + 1];
				}
 			}
		}
	}
    return output;
}

int main(void)
{
    char* str1 = "ddf6vewg64f";
    char* str2 = "gtwthgdwthdwfteewhrtag6h4ffdhsd";
    char* stringy = inter(str1, str2);
    printf("Output = %s\n", stringy);
}