#include <iostream>
#include <vector>

#define MAX 101

using namespace std;

vector <int> adj_list[MAX];

int main()
{
    int n, e, i, j, x, y;
    cout << "Enter number of nodes and edges : ";
    cin >> n >> e;

    cout << "\nEnter the undirected graph :\n";
    for(i = 1; i <= e; i++){
        cin >> x >> y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }

    cout << "\nThe graph :\n";
    for(int i = 1; i <= n; i++){
        cout << i << " ->";
        for(int x : adj_list[i]) cout << " " << x;
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
1 -> 2 4 3
2 -> 1 3
3 -> 4 1 2
4 -> 1 3
*/
