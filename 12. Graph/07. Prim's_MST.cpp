/*
MST of a graph is a spanning tree in which the sum of the edge weights is minimum.
Time complexity is O(ElogE).

Syntax => std :: priority_queue <object_type, container_type, order_of_sorting> name;
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 101
#define pii pair <int, int>

using namespace std;

bool vis[MAX];
int n, e, total_wt;
vector <pii> G[MAX];

void input_graph()
{
    int i, u, v, wt;
    cout << "Number of nodes and edges : ";
    cin >> n >> e;

    cout << "\nEnter the weighted graph\n";
    for(i = 1; i <= e; i++)
    {
        cin >> u >> v >> wt;
        G[u].push_back({wt, v});
        G[v].push_back({wt, u});
    }
    cout << "\n";
    return;
}

void prims_mst()
{
    priority_queue <pii, vector <pii>, greater<pii>> pq;
    pq.push({0, 1});          // {weight, terminal node}

    while(!pq.empty())
    {
        auto x = pq.top();
        int u = x.second;
        int u_wt = x.first;
        pq.pop();

        if(!vis[u])
        {
            vis[u] = true;
            total_wt += u_wt;

            for(auto y : G[u])
            {
                int v = y.second;
                if(!vis[v])
                {
                    pq.push(y);
                }
            }
        }
    }
    return;
}

int main()
{
    input_graph();
    prims_mst();
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
