#include <iostream>
#include <vector>

#define MAX 20
#define INF 1e9
#define EMPTY -1
#define pii pair <int, int>

using namespace std;

int n, e, cnt;
int dp[MAX];             //dp[i] will store the shortest distance from node i to destination.
vector <pii> G[MAX + 1];

void input_graph()
{
    int i, u, v, wt;
    cout << "Number of nodes and edges : ";
    cin >> n >> e;

    cout << "\nEnter the directed acyclic graph\n";
    for(int i = 1; i <= e; i++){
        cin >> u >> v >> wt;
        G[u].push_back({v, wt});
    }
    cout << "\n";
    return;
}

void init()
{
    for(int i = 1; i <= MAX; ++i){
        dp[i] = EMPTY;
    }
    return;
}

//Time complexity is O(n^2).
int shortest_distance(int u, int des)
{
    ++cnt;
    if(u == des){
        dp[u] = 0;
    }
    else if(dp[u] == EMPTY){
        int ans = INF;
        for(auto x : G[u]){
            int dis;
            int v = x.first;
            int wt = x.second;

            if(dp[v] == EMPTY){
                dis = shortest_distance(v, des) + wt;
            }
            else{
                dis = dp[v] + wt;
            }
            ans = min(ans, dis);
        }
        dp[u] = ans;
    }
    return dp[u];
}

int main()
{
    int src, des;
    input_graph();
    cout << "Enter source and destination : ";
    cin >> src >> des;

    init();
    printf("\nShortest distance from %d to %d = %d\n", src, des, shortest_distance(src, des));
    printf("Total function calls = %d\n", cnt);
    return 0;
}

/*
Number of nodes and edges : 6 8

Enter the directed acyclic graph
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
Total function calls = 6
*/
