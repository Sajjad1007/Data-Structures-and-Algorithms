/*
BFS algorithm can be used to find the shortest distances between two nodes.
Time complexity is O(n + e)
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

int n, e;
int dis[MAX]; //for an unweighted graph, level and distance are same
bool vis[MAX];
vector <int> adj[MAX];

void bfs(int src)
{
    queue <int> q;

    cout << "\nBFS Spanning Tree (level-order traversal) : ";
    cout << src;
    vis[src] = true;
    dis[src] = 0;
    q.push(src);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(!vis[v]){
                cout << " " << v;
                vis[v] = true;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    cout << '\n';

    for(int i = 1; i <= n; i++){
        cout << "\nDistance from " << src << " to " << i << " is " << dis[i];
    }
    cout << '\n';
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

    bfs(src);
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

BFS Spanning Tree (level-order traversal) : 6 5 3 4 7 1 2

Distance from 6 to 1 is 3
Distance from 6 to 2 is 3
Distance from 6 to 3 is 2
Distance from 6 to 4 is 2
Distance from 6 to 5 is 1
Distance from 6 to 6 is 0
Distance from 6 to 7 is 2
*/
