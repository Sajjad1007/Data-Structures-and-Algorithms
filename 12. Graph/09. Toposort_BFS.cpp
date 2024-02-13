/*
Topological sort is used for ordering tasks based on requirements. It is only valid in a directed acyclic graph(DAG).
The topological sort algorithm that implemented below is famously known as Kahn's algorithm.
Time complexity is O(V+E).
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

int n, e;
int indeg[MAX];
vector <int> nodes;
vector <int> G[MAX];

void input_graph()
{
    int i, u, v;
    cout << "Number of nodes and edges : ";
    cin >> n >> e;

    cout << "\nEnter the directed acyclic graph\n";
    for(i = 1; i <= e; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        indeg[v]++;
    }
    cout << "\n";
    return;
}

void toposort()
{
    int u;
    queue <int> q;

    for(u = 1; u <= n; u++)
    {
        if(indeg[u] == 0)
        {
            q.push(u);
        }
    }

    while(!q.empty())
    {
        u = q.front();
        nodes.push_back(u);
        q.pop();

        for(auto v : G[u])
        {
            indeg[v]--;
            if(indeg[v] == 0)
            {
                q.push(v);
            }
        }
    }
    return;
}

void print_order()
{
    cout << "Topological order :";
    for(auto x : nodes)
    {
        cout << " " << x;
    }
    return;
}

int main()
{
    input_graph();
    toposort();
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

Topological order : 1 2 3 6 4 5
*/
