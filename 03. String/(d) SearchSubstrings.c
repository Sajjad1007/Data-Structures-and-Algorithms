#include <stdio.h>
#include <string.h>

int main(void)
{
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
            printf("\nThe substring is present from position %d onwards",i+1);
            i += j;
        }
    }
    printf("\n");
    return 0;
}
