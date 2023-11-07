//Time complexity is O(V + E).

#include <iostream>
#include <vector>
#include <stack>

#define MAX 101

using namespace std;

int n, e;
bool vis[MAX];
stack <int> s;
vector <int> G[MAX];

void input_graph()
{
    int i, u, v;
    cout << "Number of nodes and edges : ";
    cin >> n >> e;

    cout << "\nEnter the directed acyclic graph\n";
    for(i = 1; i <= e; i++){
        cin >> u >> v;
        G[u].push_back(v);
    }
    cout << "\n";
    return;
}

void toposort(int u)
{
    vis[u] = true;
    for(auto v : G[u]){
        if(!vis[v]){
            toposort(v);
        }
    }
    s.push(u);        //All children of u has been explored.
    return;
}

void print_order()
{
    cout << "Topological order :";
    while(!s.empty()){
        cout << " " << s.top();
        s.pop();
    }
    return;
}

int main()
{
    input_graph();
    for(int u = 1; u <= n; u++){
        if(!vis[u]){
            toposort(u);
        }
    }
    print_order();
    cout << "\n";
    return 0;
}

/*
Number of nodes and edges : 6 8

Enter the directed acyclic graph
1 3
2 3
3 4
3 5
3 6
4 5
6 5
6 4

Topological order : 2 1 3 6 4 5
*/
