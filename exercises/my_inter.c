#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

char second_string(char* string, char c)
{
    for (int i = 0; i < strlen(string); i++) 
    {
        if (string[i] == c) 
            return string[i];
    }
return '\0';
}

char* inter(char* param_1, char* param_2)
{
    int i = 0, j = 0, k = 0, len = strlen(param_2);
    char* output = malloc(sizeof(char) * strlen(param_1)); 
    for(i = 0; i < strlen(param_1); i++)
    {
        output[i]= second_string(param_2, param_1[i]);
    }
        printf("ouput = %s\n", output);


    for (i = 0; i < strlen(output); i++)
  	{
  		for(j = i + 1; output[j] != '\0'; j++)
  		{
  			if(output[j] == output[i])  
			{
  				for(k = j; output[k] != '\0'; k++)
				{
					output[k] = output[k + 1];
				}
 			}
		}
	}
    printf("%s\n", output);
    return output;
}
int main(void)
{
    char* str1 = "zpadinton";
    char* str2 = "paqefwtdjetyiytjneytjoeyjnejeyj";
    char* stringy = inter(str1, str2);
     printf("Output = %s\n", stringy);
}