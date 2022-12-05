/*
Syntax => std :: priority_queue <objectType, containerType, orderOfSorting> name;
Time complexity is O(nlogn)
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

int n, e;
bool vis[MAX];
vector <pair <int, int>> adj[MAX];
priority_queue <pair <int, int>, vector <pair <int, int>>, greater<pair <int, int>>> pq;

void mst(int src)
{
    int totalWt = 0;
    pq.push({0, src});

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int u = it.second;

        if(!vis[u]){
            vis[u] = true;
            totalWt += it.first;

            for(auto v : adj[u]){
                if(!vis[v.first]) pq.push({v.second, v.first});
            }
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
