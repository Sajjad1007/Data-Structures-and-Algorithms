#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char str[100], pat[20];

bool is_equal(int indx)
{
    int plen = strlen(pat);

    for(int i = 0; i < plen; i++)
    {
        if(pat[i] != str[indx++])
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    printf("Enter the string  : ");
    scanf(" %[^\n]", str);
    printf("Enter the pattern : ");
    scanf(" %[^\n]", pat);

    int n = strlen(str);
    int m = strlen(pat);
    int l, r, pat_hash = 0, hash_value = 0;

    for(int i = 0; i < n; i++)
    {
        pat_hash += (int)pat[i];
    }

    for(l = 0, r = 0; r < n; r++)
    {
        if(r >= m)
        {
            if(hash_value == pat_hash && is_equal(l))
            {
                break;
            }
            hash_value -= (int)str[l++];
        }
        hash_value += (int)str[r];
    }

    if(r < n || (hash_value == pat_hash && is_equal(l)))
    {
        printf("\nPattern is found at index %d.\n", l);
    }
    else
    {
        printf("\nPattern is not found.\n");
    }
    return 0;
}

/*
Enter the string  : Sad but true
Enter the pattern : but

Pattern is found at index 4.
*/
