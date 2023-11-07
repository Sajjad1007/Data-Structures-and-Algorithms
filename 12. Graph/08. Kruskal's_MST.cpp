//Time complexity is O(ElogE).

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 101

using namespace std;

int n, e, total_wt, parent[MAX];
vector <pair<int, pair<int, int>>> edges;

void input_graph()
{
    int i, u, v, wt;
    cout << "Number of nodes and edges : ";
    cin >> n >> e;

    cout << "\nEnter the weighted graph\n";
    for(i = 1; i <= e; i++){
        cin >> u >> v >> wt;
        edges.push_back({wt, {u, v}});       //{weight, {initial node, terminal node}}
    }
    cout << "\n";
    return;
}

void init()
{
    for(int u = 1; u <= n; u++){
        parent[u] = u;
    }
    return;
}

int Find(int u)
{
    if(parent[u] == u){
        return u;
    }
    parent[u] = Find(parent[u]);
    return parent[u];
}

void Union(int u, int v)
{
    int p = Find(u);
    int q = Find(v);
    parent[q] = p;
    return;
}

void kruskals_mst()
{
    init();
    sort(edges.begin(), edges.end());

    for(auto x : edges){
        int wt = x.first;
        int u = x.second.first;
        int v = x.second.second;

        if(Find(u) != Find(v)){
            total_wt += wt;
            Union(u, v);
        }
    }
    return;
}

int main()
{
    input_graph();
    kruskals_mst();
    cout << "Total weight of MST = " << total_wt << "\n";
    return 0;
}

/*
Number of nodes and edges : 8 11

Enter the weighted graph
1 2 4
1 5 2
1 4 10
2 3 18
2 4 8
5 4 5
3 4 11
4 7 11
4 8 9
7 6 1
8 6 2

Total weight of MST = 34
*/
