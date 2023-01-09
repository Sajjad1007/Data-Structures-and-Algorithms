/*
Topological sort is used for ordering tasks based on requirements. It is only valid in a directed acyclic graph(DAG).
The topological sort algorithm that implemented below is famously known as Kahn's algorithm.
Time complexity is O(N + E)
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

int N, E;
int indegree[MAX];
vector <int> G[MAX];

void topsort()
{
    int node;
    queue <int> q;

    for(node = 1; node <= N; node++){
        for(auto adjNode : G[node]) indegree[adjNode]++;
    }

    for(node = 1; node <= N; node++){
        if(indegree[node] == 0) q.push(node);
    }

    while(!q.empty()){
        node = q.front();
        q.pop();
        cout << " " << node;

        for(auto adjNode : G[node]){
            indegree[adjNode]--;
            if(indegree[adjNode] == 0) q.push(adjNode);
        }
    }
    return;
}

int main()
{
    int i, node, adjNode;
    cout << "Enter number of nodes and edges : ";
    cin >> N >> E;

    cout << "\nEnter the directed acyclic graph :\n";
    for(i = 1; i <= E; i++){
        cin >> node >> adjNode;
        G[node].push_back(adjNode);
    }

    cout << "\nTopological order :";
    topsort();
    cout << '\n';
    return 0;
}

/*
Enter number of nodes and edges : 6 6

Enter the directed acyclic graph :
5 6
4 6
5 2
4 1
2 3
3 1

Topological order : 4 5 6 2 3 1
*/
