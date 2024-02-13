#include <iostream>
#include <vector>

#define INF 1e9
#define MAX 100

using namespace std;

int dp[MAX+1];                     // 'dp[i]' will store the minimum number of coins needed to change i.
vector <int> coins;

void init()
{
    for(int i = 1; i <= MAX; i++)
    {
        dp[i] = INF;
    }
    return;
}

// Time complexity is O(n^2).
int min_coin(int sum, int n)
{
    for(int tk = 1; tk <= sum; tk++)
    {
        for(auto c : coins)
        {
            if(c <= tk)            // We have infinite number of coins.
            {
                dp[tk] = min(dp[tk], 1+dp[tk-c]);
            }
        }
    }
    return dp[sum];
}

int main()
{
    int i, x, n, sum;
    cout << "Enter the amount : ";
    cin >> sum;
    cout << "\nNumber of different coins : ";
    cin >> n;
    cout << "Enter the different coins : ";

    for(i = 1; i <= n; i++)
    {
        cin >> x;
        coins.push_back(x);
    }

    init();
    n = min_coin(sum, n);
    if(n != INF)
    {
        cout << "\nMinimum coins needed = " << n << "\n";
    }
    else
    {
        cout << "\n" << sum << " cannot be changed\n";
    }
    return 0;
}

/*
Enter the amount : 22

Number of different coins : 5
Enter the different coins : 2 5 9 13 15

Minimum coins needed = 2
*/
