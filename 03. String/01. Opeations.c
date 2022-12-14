#include <stdio.h>

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
        if(str[i] == ' ' && (str[i+1] != ' ' && str[i+1] != '\0')) cnt++;
    }
    return cnt;
}

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void reverseOf(char str[])
{
    int i, j = lengthOf(str)-1;
    for(i = 0; i < j; i++, j--) swap(&str[i], &str[j]);
    return;
}

void isPalindrome(char str[])
{
    int i, j = lengthOf(str)-1;
    for(i = 0; i < j; i++, j--){
        if(str[i] != str[j]) break;
    }

    if(i >= j) printf("So \'%s\' is a palindrome\n", str);
    else printf("So \'%s\' is not a palindrome\n", str);
    return;
}

char toLower(char c)
{
    if(c >= 65 && c <= 90) return c+32;
    else return c;
}

void getDuplicates(char str[])
{
    int hash[26] = {0}, i;

    printf("\nDuplicate element(s) :");
    for(i = 0; str[i] != '\0'; i++){
        hash[toLower(str[i])-'a']++;
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
    if(lengthOf(str1) < lengthOf(str2)){
        printf("\n\'%s\' is smaller than \'%s\'\n", str1, str2);
        return;
    }
    else if(lengthOf(str1) > lengthOf(str2)){
        printf("\n\'%s\' is greater than \'%s\'\n", str1, str2);
        return;
    }
    else{
        int i = 0;
        while(str1[i] != '\0'){
            if(toLower(str1[i]) < toLower(str2[i])){
                printf("\n\'%s\' is smaller than \'%s\'\n", str1, str2);
                return;
            }
            else if(toLower(str1[i]) > toLower(str2[i])){
                printf("\n\'%s\' is greater than \'%s\'\n", str1, str2);
                return;
            }
        }
        printf("\n\'%s\' is equal to \'%s\'\n", str1, str2);
        return;
    }
}

int main(void)
{
    char str[100]; //if strings are declared as character arrays rather than pointers, they are mutable
    char str2[100];
    printf("Enter a string (lowercase preferable) : ");
    scanf(" %[^\n]", str);
    printf("\nLength of the string = %d\n", lengthOf(str));
    printf("The string has %d word(s)\n", countWords(str));
    getDuplicates(str);
    reverseOf(str);
    printf("\nReverse of the string : %s\n", str);
    isPalindrome(str);

    printf("\nEnter another string (lowercase preferable) : ");
    scanf(" %[^\n]", str2);
    reverseOf(str);
    compare(str, str2);
    return 0;
}

/*
Enter a string (lowercase preferable) : computer science and engineering

Length of the string = 32
The string has 4 word(s)

Duplicate element(s) : c (3 times)  e (6 times)  g (2 times)  i (3 times)  n (5 times)  r (2 times)

Reverse of the string : gnireenigne dna ecneics retupmoc
So 'gnireenigne dna ecneics retupmoc' is not a palindrome

Enter another string (lowercase preferable) : electrical and electronic engineering

'computer science and engineering' is smaller than 'electrical and electronic engineering'
*/
