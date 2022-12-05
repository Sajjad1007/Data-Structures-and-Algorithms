//Time complexity is O(n + e)

#include <iostream>
#include <vector>

#define MAX 101

using namespace std;

int n, e;
bool vis[MAX];
vector <int> adj[MAX];

void dfs(int src)
{
    cout << " " << src;
    vis[src] = true;
    for(int v : adj[src]){
        if(!vis[v]) dfs(v);
    }
    return;
}

int main()
{
    int x, y, src;
    cout << "Enter number of nodes and edges : ";
    cin >> n >> e;

    cout << "\nEnter the unweighted graph :\n";
    for(int i = 1; i <= e; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << "\nEnter source : ";
    cin >> src;

    cout << "\nThe graph :\n";
    for(int i = 1; i <= n; i++){
        cout << i << " -> ";
        for(int x : adj[i]){
            cout << x << " ";
        }
        cout << '\n';
    }

    cout << "\nDFS Spanning Tree (pre-order traversal) of the graph connected to node " << src << " :";
    dfs(src);
    cout << '\n';
    return 0;
}

/*
input:

Enter number of nodes and edges : 7 9

Enter the unweighted graph :
1 2
1 3
1 4
2 3
3 4
3 5
4 5
5 6
5 7

Enter source : 6

output:

The graph :
1 -> 2 3 4
2 -> 1 3
3 -> 1 2 4 5
4 -> 1 3 5
5 -> 3 4 6 7
6 -> 5
7 -> 5

DFS Spanning Tree (pre-order traversal) of the graph connected to node 6 : 6 5 3 1 2 4 7
*/
