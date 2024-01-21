#include <stdio.h>
#include <string.h>

char *to_lower(char str[])
{
    int i, len = strlen(str);
    for(i = 0; i < len; i++)
    {
        if(str[i] >= 65 && str[i] <= 90)
        {
            str[i] += 32;
        }
    }
    return str;
}

// Anagrams are two set of strings which are formed using same set of alphabets.
void anagram(char str1[], char str2[])
{
    int i, sum = 0, hash[26] = {0};
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    str1 = to_lower(str1);
    str2 = to_lower(str2);

    if(len1 != len2)
    {
        printf("\nThe strings are not anagram\n");
        return;
    }

    for(i = 0; str1[i] != '\0'; i++)
    {
        hash[str1[i]-'a']++;
    }

    for(i = 0; str2[i] != '\0'; i++)
    {
        hash[str2[i]-'a']--;
        if(hash[str2[i]-'a'] < 0)
        {
            printf("\nThe strings are not anagram\n");
            return;
        }
    }
    printf("\nThe strings are anagram\n");
    return;
}

int main(void)
{
    char str1[100], str2[100];
    printf("Enter 1st string (in lowercase) : ");
    scanf(" %[^\n]", str1);
    printf("Enter 2nd string (in lowercase) : ");
    scanf(" %[^\n]", str2);
    anagram(str1, str2);
    return 0;
}

/*
Enter 1st string : a gentleman
Enter 2nd string : elegant man

The strings are anagram
*/
