#include <iostream>

#define MAX 21
#define EMPTY -1

using namespace std;

string s, w;
int cnt, slen, wlen;
int dp[MAX][MAX];        // 'dp[i][j]' will store the length of LCS from ith index of s and jth index of w.

void init()
{
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            dp[i][j] = EMPTY;
        }
    }
    return;
}

// Time complexity is O(n^2).
int lcs_length(int i, int j)
{
    ++cnt;
    if(i == slen || j == wlen)
    {
        dp[i][j] = 0;
    }
    else if(dp[i][j] == EMPTY)
    {
        int ans = 0;
        if(s[i] == w[j])
        {
            ans += 1;    // Because of s[i] == w[j], the length of LCS is increased by 1.
            ans += (dp[i+1][j+1] == EMPTY) ? lcs_length(i+1, j+1) : dp[i+1][j+1];
        }
        else
        {
            int len1 = (dp[i+1][j] == EMPTY) ? lcs_length(i+1, j) : dp[i+1][j];
            int len2 = (dp[i][j+1] == EMPTY) ? lcs_length(i, j+1) : dp[i][j+1];
            ans = max(len1, len2);
        }
        dp[i][j] = ans;
    }
    return dp[i][j];
}

int main()
{
    cout << "Enter 1st string : ";
    getline(cin, s);
    cout << "Enter 2nd string : ";
    getline(cin, w);

    init();
    slen = s.size();
    wlen = w.size();
    cout << "\nLength of LCS = " << lcs_length(0, 0) << "\n";
    cout << "Total function calls = " << cnt << "\n";
    return 0;
}

/*
Enter 1st string : hellom
Enter 2nd string : hmrll

Length of LCS = 3
Total function calls = 28
*/
