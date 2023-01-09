//Time complexity is O(N + E)

#include <iostream>
#include <vector>
#include <stack>

#define MAX 101

using namespace std;

int N, E;
bool vis[MAX];
stack <int> s;
vector <int> G[MAX];

void topsort(int node)
{
    vis[node] = true;
    for(auto adjNode : G[node]){
        if(!vis[adjNode]) topsort(adjNode);
    }

    s.push(node); //all children of u has been explored
    return;
}

int main()
{
    int node, adjNode;
    cout << "Enter number of nodes and edges : ";
    cin >> N >> E;

    cout << "\nEnter the directed acyclic graph :\n";
    for(int i = 1; i <= E; i++){
        cin >> node >> adjNode;
        G[node].push_back(adjNode);
    }

    for(node = 1; node <= N; node++){
        if(!vis[node]) topsort(node);
    }

    cout << "\nTopological order :";
    while(!s.empty()){
        cout << " " << s.top();
        s.pop();
    }
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

Topological order : 5 4 6 2 3 1
*/
