#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int count;
bool flag[5]; //ith flag will track whether ith str stored in res or not
char res[6]; //this will be used for printing permutations of strings

/*
Here the backtracking approach is used for finding permutations of the string
after doing some operations, going back and taking another possible root is called backtracking
*/
void printPermutations(char str[], int k)
{
    int i;
    if(str[k] == '\0'){
        res[k] = '\0';
        printf("%d. %s\n", ++count, res);
    }
    else{
        for(i = 0; i < strlen(str); i++){
            if(flag[i] == false){
                res[k] = str[i];
                flag[i] = true;
                printPermutations(str, k+1);
                flag[i] = false;
            }
        }
    }
    return;
}

int main(void)
{
    char str[6];
    printf("Enter a word (maximum 5 letters) : ");
    scanf("%s", str);
    int l = 0, h = strlen(str)-1;
    printf("\nAll possible permutations of the given string :\n\n");
    printPermutations(str, 0);
    return 0;
}
