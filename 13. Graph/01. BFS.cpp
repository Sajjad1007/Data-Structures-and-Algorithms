/*
BFS can be used to find the shortest distance between two nodes in an unweighted graph.
Time and space complexity is O(N + E)
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

int N, E; //N = number of nodes, E = number of edges
int dis[MAX]; //for an unweighted graph, level and distance both can be calculated by a single array
bool vis[MAX];
vector <int> G[MAX];

void bfs(int src)
{

    queue <int> q;

    cout << "\nBFS Spanning Tree (level-order traversal) :";
    vis[src] = true;
    dis[src] = 0;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << " " << node;

        for(auto adjNode : G[node]){
            if(!vis[adjNode]){
                vis[adjNode] = true;
                dis[adjNode] = dis[node] + 1; //for an unweighted graph, we assume edge cost = 1
                q.push(adjNode);
            }
        }
    }
    cout << '\n';

    for(int node = 1; node <= N; node++){
        cout << "\nDistance from " << src << " to " << node << " is " << dis[node];
    }
    cout << '\n';
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
    bfs(src);
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

BFS Spanning Tree (level-order traversal) : 6 5 3 4 7 1 2

Distance from 6 to 1 is 3
Distance from 6 to 2 is 3
Distance from 6 to 3 is 2
Distance from 6 to 4 is 2
Distance from 6 to 5 is 1
Distance from 6 to 6 is 0
Distance from 6 to 7 is 2
*/
