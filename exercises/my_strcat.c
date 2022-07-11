#include <stdio.h>
#include <string.h>

char *my_strcat(char *dest, char *src)
{
	int	len = my_strlen(dest);
	int i = 0;
	while (src[i])
		dest[len + i] = src[i++];
	dest[len + i] = '\0';
	return (dest);
}

char *my_strcat(char *param_1, char *param_2)
{
  int j = 0;
  int i = 0;
  while (param_1[i])
      i++;
  while (param_2[j])
    {
      param_1[i] = param_2[j];
      i++;
      j++;
    }
  param_1[i] = '\0';
  return param_1;
}