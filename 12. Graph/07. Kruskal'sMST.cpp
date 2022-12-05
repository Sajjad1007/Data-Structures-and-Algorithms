//Time complexity is O(nlogn)

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 101

using namespace std;

int n, e;
int parent[MAX];
vector <pair <int, int>> adj[MAX];

void makeSet()
{
    int i;
    for(i = 1; i <= n; i++) parent[i] = i;
    return;
}

int Find(int u)
{
    if(parent[u] == u) return u;
    parent[u] = Find(parent[u]);
    return parent[u];
}

void Union(int u, int v)
{

    int p = Find(u);
    int q = Find(v);

    if(q != 0) parent[q] = p;
    else parent[v] = p;
    return;
}

void mst(int src)
{
    int i, u, v, wt, totalWt = 0;
    vector <pair<int, pair<int, int>>> edges;

    for(i = 1; i <= n; i++){
        u = i;
        for(auto x : adj[u]){
            v = x.first;
            wt = x.second;
            edges.push_back({wt, {u, v}});
        }
    }

    sort(edges.begin(), edges.end());

    for(auto x : edges){
        wt = x.first;
        u = x.second.first;
        v = x.second.second;

        if(Find(u) != Find(v)){
            totalWt += wt;
            Union(u, v);
        }
    }

    cout << "\nTotal weight of MST = " << totalWt << '\n';
    return;
}

int main()
{
    int x, y, c, src;
    cout << "Enter number of nodes and edges : ";
    cin >> n >> e;

    cout << "\nEnter the weighted graph :\n";
    for(int i = 1; i <= e; i++){
        pair <int, int> a, b;
        cin >> x >> y >> c;
        adj[x].push_back({y, c});
        adj[y].push_back({x, c});
    }

    cout << "\nEnter source : ";
    cin >> src;
    makeSet();
    mst(src);
    return 0;
}

/*
input:

Enter number of nodes and edges : 8 11

Enter the weighted graph :
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

Enter source : 1

output:

Total weight of MST = 34
*/
