#include <stdio.h>
#include <string.h>

char* my_strdup(char* param_1)
{
    char* ptr;
	int len = strlen(param_1) + 1;
	ptr = malloc(len);
	if(ptr == NULL)
		return (NULL);
	ptr = strcpy(ptr, param_1);
	ptr[len - 1] = '\0';
	return (ptr);
}