#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int length(char str[])
{
    int cnt = 0;
    while(str[cnt] != '\0')
    {
        cnt++;
    }
    return cnt;
}

int count_words(char str[])
{
    int i, cnt = 1;
    for(i = 0; str[i] != '\0'; i++)     // '\0' is sometimes called as string delimiter.
    {
        if(str[i] == ' ' && (str[i+1] != ' ' && str[i+1] != '\0'))
        {
            cnt++;
        }
    }
    return cnt;
}

char *reverse(char str[])
{
    int i, len = length(str);
    char *rev = (char *)malloc(len*sizeof(char));

    for(i = 0; i < len; i++)
    {
        rev[i] = str[len-(i+1)];
    }
    return rev;
}

char to_lower(char c)
{
    if(c >= 65 && c <= 90)
    {
        return (c+32);
    }
    else
    {
        return c;
    }
}

void duplicates(char str[])
{
    int i, hash[26] = {0};

    printf("Duplicate element(s) : ");
    for(i = 0; str[i] != '\0'; i++)
    {
        hash[to_lower(str[i])-'a']++;
    }

    for(i = 0; i < 26; i++)
    {
        if(hash[i] > 1)
        {
            printf("%c (%d times) ", 'a'+i, hash[i]);
        }
    }
    printf("\n\n");
    return;
}

// Masking determines whether a particular bit is ON or OFF(by AND operation).
// Merging helps to set a particular bit ON(by OR operation).
void compare(char str1[], char str2[])
{
    int i = 0;
    while(str1[i] != '\0')
    {
        if(to_lower(str1[i]) < to_lower(str2[i]))
        {
            printf("\n\'%s\' is smaller than \'%s\'\n\n", str1, str2);
            return;
        }
        else if(to_lower(str1[i]) > to_lower(str2[i]))
        {
            printf("\n\'%s\' is greater than \'%s\'\n\n", str1, str2);
            return;
        }
    }
    printf("\n\"%s\" is equal to \"%s\"\n\n", str1, str2);
    return;
}

void choice_list()
{
    printf("Menu\n");
    printf("1. Length\n");
    printf("2. Number of words\n");
    printf("3. Duplicate letters\n");
    printf("4. Reverse\n");
    printf("5. Compare\n");
    printf("6. Quit\n");
    return;
}

int main(void)
{
    int ch;
    char str[100], com[100];  // If strings are declared as character arrays rather than pointers, they are mutable.

    while(true)
    {
        choice_list();
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter a string : ");
                scanf(" %[^\n]", str);
                printf("Length = %d\n\n", length(str));
                break;

            case 2:
                printf("\nEnter a string : ");
                scanf(" %[^\n]", str);
                printf("Number of words = %d\n\n", count_words(str));
                break;

            case 3:
                printf("\nEnter a string : ");
                scanf(" %[^\n]", str);
                duplicates(str);
                break;

            case 4:
                printf("\nEnter a string : ");
                scanf(" %[^\n]", str);
                printf("Reverse of the string : %s\n\n", reverse(str));
                break;

            case 5:
                printf("\nEnter 1st string : ");
                scanf(" %[^\n]", str);
                printf("Enter 2nd string : ");
                scanf(" %[^\n]", com);
                compare(str, com);
                break;

            case 6:
                printf("\nFee Amanillah\n");
                return 0;

            default:
                printf("\nInvalid choice\n\n");
                break;
        }
    }
}

/*
Menu driven program
*/
