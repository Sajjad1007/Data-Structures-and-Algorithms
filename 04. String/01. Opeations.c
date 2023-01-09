#include <stdio.h>
#include <stdlib.h>

int lengthOf(char str[])
{
    int cnt;
    for(cnt = 0; str[cnt] != '\0'; cnt++);
    return cnt;
}

int countWords(char str[])
{
    int i, cnt = 1;
    for(i = 0; str[i] != '\0'; i++){ //'\0' is sometimes called as 'string delimiter'
        if(str[i] == ' ' && (str[i + 1] != ' ' && str[i + 1] != '\0')) cnt++;
    }
    return cnt;
}

char* reverseOf(char str[])
{
    int i, len = lengthOf(str);
    char* rev = (char *)malloc(len * sizeof(char));

    for(i = 0; i < len; i++) rev[i] = str[len - (i + 1)];
    return rev;
}

void isPalindrome(char str[])
{
    int i, j = lengthOf(str) - 1;
    for(i = 0; i < j; i++, j--){
        if(str[i] != str[j]) break;
    }

    if(i >= j) printf("So \"%s\" is a palindrome\n", str);
    else printf("So \"%s\" is not a palindrome\n", str);
    return;
}

char toLower(char c)
{
    if(c >= 65 && c <= 90) return c + 32;
    else return c;
}

void getDuplicates(char str[])
{
    int hash[26] = {0}, i;

    printf("\nDuplicate element(s) :");
    for(i = 0; str[i] != '\0'; i++){
        hash[toLower(str[i]) - 'a']++;
    }
    for(i = 0; i < 26; i++){
        if(hash[i] > 1){
            printf(" %c (%d times) ", 'a' + i, hash[i]);
        }
    }
    printf("\n");
    return;
}

//Masking determines whether a particular bit is ON or OFF (by AND operation)
//Merging helps to set a particular bit ON (by OR operation)
void compare(char str1[], char str2[])
{
    int i = 0;
    while(str1[i] != '\0'){
        if(toLower(str1[i]) < toLower(str2[i])){
            printf("\n\"%s\" is smaller than \"%s\"\n", str1, str2);
            return;
        }
        else if(toLower(str1[i]) > toLower(str2[i])){
            printf("\n\"%s\" is greater than \"%s\"\n", str1, str2);
            return;
        }
    }
    printf("\n\"%s\" is equal to \"%s\"\n", str1, str2);
    return;
}

int main(void)
{
    char str1[100]; //if strings are declared as character arrays rather than pointers, they are mutable
    char str2[100];
    printf("Enter a string (lowercase preferable) : ");
    scanf(" %[^\n]", str1);
    printf("\nLength of the string = %d\n", lengthOf(str1));
    printf("The string has %d word(s)\n", countWords(str1));
    getDuplicates(str1);
    printf("\nReverse of the string : %s\n", reverseOf(str1));
    isPalindrome(str1);

    printf("\nEnter another string (lowercase preferable) : ");
    scanf(" %[^\n]", str2);
    compare(str1, str2);
    return 0;
}

/*
Enter a string (lowercase preferable) : computer science and engineering

Length of the string = 32
The string has 4 word(s)

Duplicate element(s) : c (3 times)  e (6 times)  g (2 times)  i (3 times)  n (5 times)  r (2 times)

Reverse of the string : gnireenigne dna ecneics retupmoc
So "computer science and engineering" is not a palindrome

Enter another string (lowercase preferable) : electrical

"computer science and engineering" is smaller than "electrical"
*/
