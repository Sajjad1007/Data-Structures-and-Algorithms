//Time and space complexity is O(V + E).

#include <iostream>
#include <vector>

#define MAX 101

using namespace std;

int n, e;
bool vis[MAX];
vector <int> nodes;
vector <int> G[MAX];

void input_graph()
{
    int i, u, v;
    cout << "Number of nodes and edges : ";
    cin >> n >> e;

    cout << "\nEnter the unweighted graph\n";
    for(i = 1; i <= e; i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cout << "\n";
    return;
}

void dfs(int u)
{
    vis[u] = true;
    nodes.push_back(u);

    for(auto v : G[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    return;
}

void print_dfs()
{
    cout << "\nDFS :";
    for(auto x : nodes){
        cout << " " << x;
    }
    return;
}

int main()
{
    int src;
    input_graph();
    cout << "Enter source : ";
    cin >> src;

    dfs(src);
    print_dfs();
    cout << "\n";
    return 0;
}

/*
Number of nodes and edges : 10 13

Enter the unweighted graph
1 2
1 4
1 3
2 6
4 7
3 7
3 8
7 9
7 8
6 10
9 10
5 8
5 10

Enter source : 1

DFS : 1 2 6 10 9 7 4 3 8 5
*/
