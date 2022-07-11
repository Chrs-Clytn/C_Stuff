#include <stdio.h>
#define NO_OF_CHARS 94

// int is_anagram(char* str1, char* str2)
// {
//     int count1[NO_OF_CHARS] = {0};
//     int count2[NO_OF_CHARS] = {0};
//     int i;
//     int wrong = 0;
//     for (i = 0; str1[i] && str2[i]; i++) 
//     {
//         count1[(int)str1[i]]++;
//         count2[(int)str2[i]]++;
//     }
//     printf("Count 1 = %ls\n", count1);
//     printf("Count 2 = %ls\n", count2);
//     if (str1[i] || str2[i])
//         return 0;
//     for (i = 0; i < NO_OF_CHARS; i++)
//     {
//         if (count1[i] != count2[i])
//             wrong++;;
//     }
//     if(wrong > 0)
//         return 0;

// return 1;
// }

int is_anagram(char* a, char* b)
{
int first[NO_OF_CHARS] = {0}, second[NO_OF_CHARS] = {0}, c=0;

// Calculating frequency of characters of first string

while (a[c] != '\0')
{
first[a[c]-'a']++;
c++;
}

c = 0;

while (b[c] != '\0')
{
second[b[c]-'a']++;
c++;
}

// Comparing frequency of characters

for (c = 0; c < 26; c++)
{
if (first[c] != second[c])
return 0;
}

return 1;
}
int main(void)
{
    char *str1 = "abcdef";
    char* str2 = "fabcde";

    printf("result = %d\n", is_anagram(str1, str2));
}