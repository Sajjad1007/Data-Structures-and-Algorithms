#include <iostream>
#include <vector>

#define INF 1e9
#define MAX 100
#define EMPTY -1

using namespace std;

int cnt, dp[MAX][MAX];        // 'dp[i][n]' will store the minimum number of multiplications required to multiply matrices from ith to nth index.

struct matrix
{
    int row;
    int col;

    matrix(int row, int col)
    {
        this->row = row;
        this->col = col;
    }
};

vector <matrix> mat;

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

int merge_cost(int i, int n, int j)
{
    int total_cost = (mat[i].row*mat[j].col)*mat[n].row;    // Total number of multiplications to multiply 3 matrices = (r1 * c3) * r2
    return total_cost;
}

//Time complexity is O(n^3).
int min_multiplication(int i, int n)
{
    cnt++;
    if(i >= n)
    {
        dp[i][n] = 0;
    }
    else if(dp[i][n] != EMPTY);
    else
    {
        int ans = INF;
        for(int j = i; j < n; j++)
        {
            int res_left = min_multiplication(i, j);
            int res_right = min_multiplication(j+1, n);
            int cost = (res_left+res_right)+merge_cost(i, n, j);
            ans = min(ans, cost);
        }
        dp[i][n] = ans;
    }
    return dp[i][n];
}

int main()
{
    int i, n, r, c;
    cout << "Number of matrices : ";
    cin >> n;
    cout << "\nEnter number of rows and number of columns of " << n << " matrices\n\n";

    for(i = 1; i <= n; i++)
    {
        cout << "Matrix " << i << " : ";
        cin >> r >> c;
        matrix m(r, c);
        mat.push_back(m);
    }

    init();
    cout << "\nMinimum number of multiplications required = " << min_multiplication(0, n-1) << "\n";
    cout << "Total function calls = " << cnt << "\n";
    return 0;
}

/*
Number of matrices : 3

Enter number of rows and number of columns of 3 matrices

Matrix 1 : 10 100
Matrix 2 : 100 5
Matrix 3 : 5 50

Minimum number of multiplications required = 7500
Total function calls = 9
*/
