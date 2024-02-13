/*
BFS can be used to find the shortest distance between two nodes in an unweighted graph.
Time and space complexity is O(V+E).
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 101
#define INF 1e9

using namespace std;

int n, e;                     // n = number of nodes, e = number of edges
int dis[MAX];                 // For an unweighted graph, level and distance both are same.
int parent[MAX];              // Parent array will be used to print shortest paths.
vector <int> nodes;           // During BFS, nodes will be stored here.
vector <int> G[MAX];          // Graph

void input_graph()
{
    int i, u, v;
    cout << "Number of nodes and edges : ";
    cin >> n >> e;

    cout << "\nEnter the unweighted graph\n";
    for(i = 1; i <= e; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
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

void bfs(int src)
{
    queue <int> q;
    init();
    dis[src] = 0;
    parent[src] = src;
    q.push(src);

    while(!q.empty())
    {
        int u = q.front();
        nodes.push_back(u);
        q.pop();

        for(auto v : G[u])                   // Traverse the adjacent nodes of u.
        {
            if(dis[v] == INF)                // INF does the work of visited array.
            {
                dis[v] = dis[u]+1;           // Edge cost is 1 for an unweighted graph.
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return;
}

void print_bfs()
{
    cout << "\nBFS :";
    for(auto x : nodes)
    {
        cout << " " << x;
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

    bfs(src);
    print_bfs();
    printf("\n\nShortest distance from %d to %d = %d\n", src, des, dis[des]);
    printf("Shortest path : ", src, des);
    print_path(des);
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

Enter source and destination : 1 10

BFS : 1 2 4 3 6 7 8 10 9 5

Shortest distance from 1 to 10 = 3
Shortest path : 1 -- 2 -- 6 -- 10
*/
