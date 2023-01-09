//Time and space complexity is O(N + E)

#include <iostream>
#include <vector>

#define MAX 101

using namespace std;

int N, E;
bool vis[MAX];
vector <int> G[MAX];

void dfs(int node)
{
    vis[node] = true;
    cout << " " << node;

    for(auto adjNode : G[node]){
        if(!vis[adjNode]) dfs(adjNode);
    }
    return;
}

int main()
{
    int i, src, node, adjNode;
    cout << "Enter number of nodes and edges : ";
    cin >> N >> E;

    cout << "\nEnter the unweighted graph :\n";
    for(i = 1; i <= E; i++){
        cin >> node >> adjNode;
        G[node].push_back(adjNode);
        G[adjNode].push_back(node);
    }

    cout << "\nThe graph :\n";
    for(node = 1; node <= N; node++){
        cout << node << " ->";
        for(auto adjNode : G[node]){
            cout << " " << adjNode;
        }
        cout << '\n';
    }

    cout << "\nEnter source : ";
    cin >> src;
    cout << "\nDFS Spanning Tree (pre-order traversal) :";
    dfs(src);
    cout << '\n';
    return 0;
}

/*
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

The graph :
1 -> 2 3 4
2 -> 1 3
3 -> 1 2 4 5
4 -> 1 3 5
5 -> 3 4 6 7
6 -> 5
7 -> 5

Enter source : 6

DFS Spanning Tree (pre-order traversal) : 6 5 3 1 2 4 7
*/
