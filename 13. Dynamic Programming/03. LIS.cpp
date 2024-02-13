#include <iostream>
#include <vector>

#define MAX 20
#define EMPTY -1

using namespace std;

int n, cnt;
int dp[MAX];             // 'dp[i]' will store the length of LIS from ith index of v.
int next_indx[MAX];      // 'next_indx[i]' will store the next index after the ith index of the LIS.
vector <int> v;

void init()
{
    for(int i = 0; i < n; ++i)
    {
        dp[i] = EMPTY;
        next_indx[i] = EMPTY;
    }
    return;
}

int lis_length(int i)
{
    ++cnt;
    if(dp[i] == EMPTY)
    {
        int ans = 0, res;
        for(int j = i+1; j < n; j++)
        {
            if(v[i] < v[j])
            {
                res = (dp[j] == EMPTY) ? lis_length(j) : dp[j];
                if(res > ans)
                {
                    ans = res;
                    next_indx[i] = j;
                }
            }
        }
        dp[i] = ans+1;
    }
    return dp[i];
}

// Time complexity is O(n^2).
int print_lis()
{
    int ans = 0, res, strt_indx = -1;

    for(int i = 0; i < n; ++i)
    {
        res = (dp[i] == EMPTY) ? lis_length(i) : dp[i];     // Calculating LIS from ith index
        if(res > ans)
        {
            ans = res;
            strt_indx = i;
        }
    }
    res = dp[strt_indx];

    cout << "\nLIS :";
    while(strt_indx != EMPTY)
    {
        cout << " " << v[strt_indx];
        strt_indx = next_indx[strt_indx];
    }
    return res;
}

int main()
{
    int i, x;
    cout << "Number of elements : ";
    cin >> n;
    cout << "Enter the elements : ";

    for(i = 1; i <= n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    init();
    int len = print_lis();
    cout << "\nLength = " << len << "\n";
    cout << "Total function calls = " << cnt << "\n";
    return 0;
}

/*
Number of elements : 7
Enter the elements : 5 0 9 2 7 3 4

LIS : 0 2 3 4
Length = 4
Total function calls = 7
*/
