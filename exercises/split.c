#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct string_array
{
    int size;
    char** array;
} string_array;
#endif

static int		wordscount(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
			if (s[i] == '\0')
				return (words);
		}
		i++;
	}
	return (words);
}

static char		**free2d(char **strarr)
{
	int	i;

	i = 0;
	while (strarr[i])
	{
		free(strarr[i]);
		i++;
	}
	free(strarr);
	return ((void *)0);
}

static int		word_end(char *s, char c, int i)
{
	int		click;

	click = 0;
	while (s && s[i] && click != 1)
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			click = 1;
		}
		if (click != 1)
			i++;
	}
	return (i);
}

static char		*word_allocate(char *s, char c, int i, int j)
{
	char	*word;
	int		click;

	click = 0;
	while (s && *s && click != 1)
	{
		if (*s != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			click = 1;
		}
		if (click != 1)
			s++;
	}
	if (!(word = malloc(i + 1)))
		return ((void *)0);
	while (s && *s && *s != c)
	{
		word[j] = *s++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

char			**new_split(char const *s, char c)
{
	char	**strarr;
	int		j;
	int		i;
	int		remember;

	if (!s)
		return ((void *)0);
	j = wordscount(s, c);
	i = 0;
	remember = 0;
	if (!(strarr = malloc(sizeof(char *) * (j + 1))))
		return ((void *)0);
	strarr[j] = (void *)0;
	while (i < j)
	{
		if (!(strarr[i] = word_allocate((char *)(s + remember), c, 0, 0)))
		{
			free2d(strarr);
			return ((void *)0);
		}
		remember = word_end((char *)s, c, remember);
		i++;
	}
	return (strarr);
}

string_array* my_split(char* str, char* delim)
{
    int words = wordscount(str, delim[0]);
    string_array* result = malloc(sizeof(string_array) * (strlen(str) + 1));
    result->size = words;
    char new_char = delim[0];
    result->array = new_split(str, new_char);
return result;
}

int main(void)
{
    my_split("abc def gh-!", "-");
return 0;
}