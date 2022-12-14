/*
MST of a graph is a spanning tree in which the sum of the weights of edges is minimum.
Syntax => std :: priority_queue <objectType, containerType, orderOfSorting> name;
Time complexity is O(ElogN)
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

int N, E;
bool vis[MAX];
vector <pair <int, int>> G[MAX];

void mst(int src)
{
    int totalWt = 0;
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater<pair <int, int>>> pq;
    pq.push({0, src}); //{weight, terminal node of an edge}

    while(!pq.empty()){
        auto pqPair = pq.top(); //it is pointing to a pair having minimum weight, pqPair = pair of pq
        pq.pop();
        int wtOfNode = pqPair.first; //wt = weight of the edge in which node is the terminal node
        int node = pqPair.second;

        if(!vis[node]){
            vis[node] = true;
            totalWt += wtOfNode;

            for(auto gPair : G[node]){ //gPair = pair of G
                int adjNode = gPair.first;
                int wtOfAdjNode = gPair.second;
                if(!vis[adjNode]) pq.push({wtOfAdjNode, adjNode});
            }
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
        G[node].push_back({adjNode, cost});
        G[adjNode].push_back({node, cost});
    }

    cout << "\nEnter source : ";
    cin >> src;
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
