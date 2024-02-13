/*
Dijkstra is used to find the shortest distance between two nodes in an weighted graph.
Time complexity is O(VlogV+E).
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 101
#define INF 1e9
#define pii pair <int, int>

using namespace std;

int n, e;
int dis[MAX];
int parent[MAX];
vector <pii> G[MAX];

void input_graph()
{
    int i, u, v, wt;
    cout << "Number of nodes and edges : ";
    cin >> n >> e;

    cout << "\nEnter the weighted graph\n";
    for(int i = 1; i <= e; i++)
    {
        cin >> u >> v >> wt;
        G[u].push_back({wt, v});
        G[v].push_back({wt, u});
    }
    cout << "\n";
    return;
}

void init()
{
    for(int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    return;
}

void dijkstra(int src)
{
    priority_queue <pii, vector <pii>, greater<pii>> pq;
    init();
    dis[src] = 0;
    parent[src] = src;
    pq.push({dis[src], src});                // {distance, terminal node}

    while(!pq.empty())
    {
        auto x = pq.top();
        int u = x.second;
        pq.pop();

        for(auto y : G[u])
        {
            int v = y.second;
            int wt = y.first;

            if(dis[u]+wt < dis[v])
            {
                dis[v] = dis[u]+wt;          // dis[v] = distance of v from source
                parent[v] = u;
                pq.push({dis[v], v});
            }
        }
    }
    return;
}

void print_path(int u)
{
    if(parent[u] == u)
    {
        cout << u;
    }
    else
    {
        print_path(parent[u]);
        cout << " -- " << u;
    }
    return;
}

int main()
{
    int src, des;
    input_graph();
    cout << "Enter source and destination : ";
    cin >> src >> des;

    dijkstra(src);
    printf("\nShortest distance from %d to %d = %d\n", src, des, dis[des]);
    printf("Shortest path : ", src, des);
    print_path(des);
    cout << "\n";
    return 0;
}

/*
Number of nodes and edges : 6 8

Enter the weighted graph
1 2 2
1 6 4
2 3 3
2 4 1
2 5 6
2 6 4
3 5 2
4 5 3

Enter source and destination : 1 5

Shortest distance from 1 to 5 = 6
Shortest path : 1 -- 2 -- 4 -- 5
*/
