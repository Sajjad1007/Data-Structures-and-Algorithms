#include <iostream>
#include <vector>

#define EMPTY -1
#define MAX_N 20
#define MAX_W 100

using namespace std;

int n, W, cnt;
int dp[MAX_N][MAX_W + 1];               //dp[i][W] will store the number of all possible combinations for the sum W from ith element.
vector <int> elem;

void init()
{
    for(int i = 0; i < MAX_N; i++){
        for(int j = 0; j <= MAX_W; j++){
            dp[i][j] = EMPTY;
        }
    }
    return;
}

//Time complexity is O(n*W).
int subset_cnt(int i, int W)
{
    ++cnt;
    if(W < 0){
        dp[i][W] = 0;
    }
    else if(i == n){
        if(W == 0){
            dp[i][W] = 1;
        }
        else if(W > 0){                 //We have reached end of the element list but we cannot form W.
            dp[i][W] = 0;
        }
    }
    else if(dp[i][W] == EMPTY){
        int cnt1 = subset_cnt(i + 1, W - elem[i]);
        int cnt2 = subset_cnt(i + 1, W);
        dp[i][W] = cnt1 + cnt2;
    }
    return dp[i][W];
}

int main()
{
    int i, e;
    cout << "Enter the sum : ";
    cin >> W;
    cout << "\nNumber of elements : ";
    cin >> n;
    cout << "Enter the elements : ";

    for(i = 1; i <= n; i++){
        cin >> e;
        elem.push_back(e);
    }

    init();
    cout << "\nNumber of subsets = " << subset_cnt(0, W) << "\n";
    cout << "Total function calls = " << cnt << "\n";
    return 0;
}

/*
Enter the sum : 20

Number of elements : 5
Enter the elements : 5 15 3 17 12

Number of subsets = 3
Total function calls = 45
*/
