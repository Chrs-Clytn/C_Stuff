#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

char* my_union(char* param_1, char* param_2)
{
    int len_1 = strlen(param_1) + 1, len_2 = strlen(param_2) + 1, i, j, k;
    char* new_str = malloc(sizeof(char) * len_1 + len_2);
    strcat(new_str, param_1);
    strcat(new_str, param_2);
    int new_len = strlen(new_str) + 1;

    for (i = 0; i < new_len; i++)
  	{
  		for(j = i + 1; new_str[j] != '\0'; j++)
  		{
  			if(new_str[j] == new_str[i])  
			{
  				for(k = j; new_str[k] != '\0'; k++)
				{
                    printf("New string K = %c and k++ = %c\n", new_str[k], new_str[k+1]);
					new_str[k] = new_str[k + 1];
				}
 			}
		}
	}
    return new_str;
}

int main(void)
{
    char* str1 = "zpadinton";
    char* str2 = "paqefwtdjetyiytjneytjoeyjnejeyj";
    printf("%s\n", my_union(str1, str2));
    char* stringy = my_union(str1, str2);
    int len = strlen(stringy) + 1;
    int i, j, k;
        
    for (i = 0; i < len; i++)
  	{
  		for(j = i + 1; stringy[j] != '\0'; j++)
  		{
  			if(stringy[j] == stringy[i])  
			{
  				for(k = j; stringy[k] != '\0'; k++)
				{
                    printf("New string K = %c and k++ = %c\n", stringy[k], stringy[k+1]);
					stringy[k] = stringy[k + 1];
				}
 			}
		}
	}
    printf("Output = %s\n", stringy);
}