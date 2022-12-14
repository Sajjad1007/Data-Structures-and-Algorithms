#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    bool flag = false;
    char str[100], substr[30];
    int lenstr, lensub, i, j;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);
    printf("Enter a sub string to be searched: ");
    scanf(" %[^\n]", substr);
    lenstr = strlen(str);
    lensub = strlen(substr);

    for(i = 0; i <= lenstr - lensub; i++){
        for(j = 0; j < lensub; j++){
            if(str[i+j] != substr[j]) break;
        }
        if(j == lensub){
            flag = true;
            printf("\nThe substring is present from position %d onwards",i+1);
            i += j;
        }
    }

    if(flag == false){
        printf("\nThe substring is not present in the string");
    }
    printf("\n");
    return 0;
}

/*
Enter a string: abccbacabbaabccbbcaac
Enter a sub string to be searched: abc

The substring is present from position 1 onwards
The substring is present from position 12 onwards
*/
