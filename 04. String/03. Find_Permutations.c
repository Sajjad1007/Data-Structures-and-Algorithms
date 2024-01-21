#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int count;
bool flag[5];       // ith value of flag will track whether ith character of str stored in res or not.
char res[6];        // This array will be used for printing permutations of the string.

/*
Here the backtracking approach is used for finding permutations of the string.
After doing some operations, going back and taking another possible root is called backtracking.
*/
void print_permutations(char str[], int k)
{
    int i;
    if(str[k] == '\0')
    {
        res[k] = '\0';
        printf("%03d  %s\n", ++count, res);
    }
    else
    {
        int len = strlen(str);
        for(i = 0; i < len; i++)
        {
            if(flag[i] == false)
            {
                res[k] = str[i];
                flag[i] = true;
                print_permutations(str, k+1);
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
    printf("\nAll possible permutations of \'%s\'\n\n", str);
    print_permutations(str, 0);
    return 0;
}

/*
Enter a word (maximum 5 letters) : abcd

All possible permutations of 'abcd'

001  abcd
002  abdc
003  acbd
004  acdb
005  adbc
006  adcb
007  bacd
008  badc
009  bcad
010  bcda
011  bdac
012  bdca
013  cabd
014  cadb
015  cbad
016  cbda
017  cdab
018  cdba
019  dabc
020  dacb
021  dbac
022  dbca
023  dcab
024  dcba
*/
