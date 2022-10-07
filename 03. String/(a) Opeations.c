#include <stdio.h>

int lengthOf(char str[])
{
    int cnt;
    for(cnt = 0; str[cnt] != '\0'; cnt++);
    return cnt;
}

int countWords(char str[])
{
    int cnt = 1;
    for(int i = 0; str[i] != '\0'; i++){ //'\0' is sometimes called as 'string delimiter'
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
    for(i = 0; i < j; i++, j--){
        swap(&str[i], &str[j]);
    }
    return;
}

void isPalindrome(char str[])
{
    int i, j = lengthOf(str)-1;
    for(i = 0; i < j; i++, j--){
        if(str[i] != str[j]) break;
    }

    if(i >= j){
        printf("So, this is a palindrome\n");
    }
    else{
        printf("So, this is not a palindrome\n");
    }
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

    printf("Duplicate element(s) :");
    for(i = 0; str[i] != '\0'; i++){
        hash[toLower(str[i])-'a']++;
    }
    for(i = 0; i < 26; i++){
        if(hash[i] > 1){
            printf("  %c(%d times)", 'a'+i, hash[i]);
        }
    }
    printf("\n");
    return;
}

//Masking determines whether a particular bit is ON or OFF (by AND operation)
//Merging helps to set a particular bit ON (by OR operation)
void compare(char str1[], char str2[])
{
    int i;
    for(i = 0; str1[i] != '\0' && str2[i] != '\0'; i++){
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
    printf("Reverse of the string : %s\n", str);
    isPalindrome(str);

    printf("\nEnter another string (lowercase preferable) : ");
    scanf(" %[^\n]", str2);
    reverseOf(str);
    compare(str, str2);
    return 0;
}
