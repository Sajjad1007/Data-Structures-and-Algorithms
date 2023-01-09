#include <stdio.h>
#include <string.h>

//Anagrams are two set of strings which are formed using same set of alphabets
void isAnagram(char str1[], char str2[])
{
    int i, sum = 0, hash[26] = {0};
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if(len1 != len2){
        printf("\nThe strings are not anagram\n");
        return;
    }

    for(i = 0; str1[i] != '\0'; i++) hash[str1[i] - 'a']++;
    for(i = 0; str2[i] != '\0'; i++){
        hash[str2[i] - 'a']--;
        if(hash[str2[i] - 'a'] < 0){
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
    isAnagram(str1, str2);
    return 0;
}

/*
Enter 1st string (in lowercase) : a gentleman
Enter 2nd string (in lowercase) : elegant man

The strings are anagram
*/
