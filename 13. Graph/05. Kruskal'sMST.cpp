//Time complexity is O(ElogN)

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 101

using namespace std;

int N, E;
int parent[MAX];
vector <pair<int, pair<int, int>>> edges;

void makeSet()
{
    int node;
    for(node = 1; node <= N; node++) parent[node] = node;
    return;
}

int Find(int node)
{
    if(parent[node] == node) return node;
    parent[node] = Find(parent[node]);
    return parent[node];
}

void Union(int node1, int node2)
{

    int parent1 = Find(node1);
    int parent2 = Find(node2);

    if(parent2 != 0) parent[parent2] = parent1;
    else parent[node2] = parent1;
    return;
}

void mst(int src)
{
    int totalWt = 0;
    sort(edges.begin(), edges.end());

    for(auto ePair : edges){
        int cost = ePair.first;
        int node = ePair.second.first;
        int adjNode = ePair.second.second;

        if(Find(node) != Find(adjNode)){
            totalWt += cost;
            Union(node, adjNode);
        }
    }

    cout << "\nTotal weight of MST = " << totalWt << '\n';
    return;
}

int main()
{
    int src, node, adjNode, cost;
    cout << "Enter number of nodes and edges : ";
    cin >> N >> E;

    cout << "\nEnter the weighted graph :\n";
    for(int i = 1; i <= E; i++){
        cin >> node >> adjNode >> cost;
        edges.push_back({cost, {node, adjNode}});
    }
    cout << "\nEnter source : ";
    cin >> src;
    makeSet();
    mst(src);
    return 0;
}

/*
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

Total weight of MST = 34
*/
