#include <stdio.h>
#include <string.h>

char str[100], pat[20];

void KMP(int n, int m)
{
    // next[i] stores the index of the next best partial match.
    int i, j, next[n+1];

    for(i = 0; i <= n; i++)
    {
        next[i] = 0;
    }

    for(i = 1; i < n; i++)
    {
        int j = next[i];

        while(j > 0 && pat[j] != pat[i])
        {
            j = next[j];
        }

        if(j > 0 || pat[j] == pat[i])
        {
            next[i+1] = j+1;
        }
    }

    for(i = 0, j = 0; i < n; i++)
    {
        if(str[i] == pat[j])
        {
            if(++j == m)
            {
                printf("\nPattern is found at index %d.\n", i-j+1);
                return;
            }
        }
        else if(j > 0)
        {
            j = next[j];
            i--;         // Since i will be incremented in the next iteration.
        }
    }

    if(i == n)
    {
        printf("\nPattern is not found.\n");
    }
    return;
}

int main(void)
{
    printf("Enter the string  : ");
    scanf(" %[^\n]", str);
    printf("Enter the pattern : ");
    scanf(" %[^\n]", pat);

    int n = strlen(str);
    int m = strlen(pat);
    KMP(n, m);
    return 0;
}
/*
Enter the string  : Sad but true
Enter the pattern : but

Pattern is found at index 4.
*/
