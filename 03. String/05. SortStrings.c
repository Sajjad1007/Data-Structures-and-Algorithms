#include <stdio.h>
#include <string.h>

void reorder(int n, char x[][20])
{
    char temp[20];
    int i, item;

    for(item = 0; item < n-1; ++item){
        for(i = item+1; i < n; ++i){
            //strcmpi() function compares strings without case sensitivity
            if(strcmpi(x[item], x[i]) > 0){
                strcpy(temp, x[item]);
                strcpy(x[item], x[i]);
                strcpy(x[i], temp);
            }
        }
    }
    return;
}

int main(void)
{
    int i = 0, n;
    printf("How many strings? ");
    scanf("%d", &n);
    char x[n][20];

    printf("\nEnter each string on a separate line below\n\n");
    do{
        printf("string %d: ", i+1);
        scanf("%s", x[i++]);
    } while(i < n);

    reorder(n, x);
    printf("\nReordered list of strings:\n\n");
    for(i = 0; i < n; ++i) printf("string %d: %s\n", i+1, x[i]);
    return 0;
}

/*
How many strings? 3

Enter each string on a separate line below

string 1: cse
string 2: swe
string 3: eee

Reordered list of strings:

string 1: cse
string 2: eee
string 3: swe
*/
