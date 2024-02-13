#include <iostream>
#include <vector>

#define INF 1e9
#define EMPTY -1
#define MAX_ITEM 20
#define MAX_CAPACITY 100

using namespace std;

int n, C, cnt;
int dp[MAX_ITEM][MAX_CAPACITY+1];       // 'dp[i][C]' will store the maximum prize for the capacity C from the ith item.
vector <int> pz, wt;

void init()
{
    for(int i = 0; i < MAX_ITEM; i++)
    {
        for(int j = 0; j <= MAX_CAPACITY; j++)
        {
            dp[i][j] = EMPTY;
        }
    }
    return;
}

// Time complexity is O(n*C).
int max_prize(int i, int C)
{
    ++cnt;
    if(C < 0)                           // If we take this item, total weights will be greater than C.
    {
        dp[i][C] = -INF;
    }
    else if(i == n)
    {
        if(C == 0)
        {
            dp[i][C] = 0;
        }
        else if(C > 0)                  // We have reached end of the item list but we cannot form the C.
        {
            dp[i][C] = -INF;
        }
    }
    else if(dp[i][C] == EMPTY)
    {
        int cnt1 = pz[i]+max_prize(i+1, C-wt[i]);
        int cnt2 = max_prize(i+1, C);
        dp[i][C] = max(cnt1, cnt2);
    }
    return dp[i][C];
}

int main()
{
    int i, p, w;
    cout << "Enter the capacity : ";
    cin >> C;
    cout << "Number of items : ";
    cin >> n;
    cout << "\nEnter the weights and prizes\n";

    for(i = 1; i <= n; i++)
    {
        cin >> w >> p;
        wt.push_back(w);
        pz.push_back(p);
    }

    init();
    cout << "\nMaximum prize = " << max_prize(0, C) << "\n";
    cout << "Total function calls = " << cnt << "\n";
    return 0;
}

/*
Enter the capacity : 15
Number of items : 5

Enter the weights and prizes
12 4
1 2
4 10
1 1
2 2

Maximum prize = 8
Total function calls = 45
*/
