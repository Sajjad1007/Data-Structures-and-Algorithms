#include <iostream>

#define MAX 101

using namespace std;

int adj_mtrx[MAX][MAX];

int main()
{
    int n, e, i, j, x, y;
    cout << "Enter number of nodes and edges : ";
    cin >> n >> e;

    cout << "\nEnter the undirected graph :\n";
    for(i = 1; i <= e; i++){
        cin >> x >> y;
        adj_mtrx[x][y] = 1;
        adj_mtrx[y][x] = 1;
    }

    cout << "\nThe graph :\n";
    for(i = 1; i <= n; i++){
        cout << i << " ->";
        for(j = 1; j <= n; j++){
            if(adj_mtrx[i][j] != 0) cout << " " << j;
        }
    cout << '\n';
    }
    return 0;
}

/*
input:

Enter number of nodes and edges : 4 5

Enter the undirected graph :
1 2
1 4
3 4
1 3
3 2

output:

The graph :
1 -> 2 3 4
2 -> 1 3
3 -> 1 2 4
4 -> 1 3
*/
