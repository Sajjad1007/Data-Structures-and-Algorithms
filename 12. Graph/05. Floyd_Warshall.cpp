/*
Floyd Warshall algorithm is used to find the shortest distance and path between all pairs in an weighted graph.
Time complexity is O(V^3).
Space complexity is O(V^2).
*/

#include <iostream>

#define MAX 101
#define INF 1e9

using namespace std;

int n, e;
int dis[MAX][MAX];
int nxt[MAX][MAX];       //nxt[i][j] will store the next node of i in order to reach j.

void init()
{
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            nxt[i][j] = j;
            if(i == j){
                continue;
            }
            dis[i][j] = INF;
        }
    }
    return;
}

void input_graph()
{
    int i, u, v, wt;
    cout << "Number of nodes and edges : ";
    cin >> n >> e;

    init();
    cout << "\nEnter the weighted graph\n";
    for(i = 1; i <= e; i++){
        cin >> u >> v >> wt;
        dis[u][v] = wt;
        dis[v][u] = wt;
    }
    cout << "\n";
    return;
}

void floyd_warshall()
{
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dis[i][j] > dis[i][k] + dis[k][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
    return;
}

void print_path(int i, int j)
{
    cout << "path : " << i;
    while(i != j){
        i = nxt[i][j];
        cout << " -- " << i;
    }
    cout << "\n";
    return;
}

int main()
{
    int i, j;
    input_graph();
    floyd_warshall();

    cout << "Shortest distances\n\n";
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            printf("From %d to %d = %d,  ", i, j, dis[i][j]);
            print_path(i, j);
        }
        if(i < n){
            cout << "\n";
        }
    }
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

Shortest distances

From 1 to 1 = 0,  path : 1
From 1 to 2 = 2,  path : 1 -- 2
From 1 to 3 = 5,  path : 1 -- 2 -- 3
From 1 to 4 = 3,  path : 1 -- 2 -- 4
From 1 to 5 = 6,  path : 1 -- 2 -- 4 -- 5
From 1 to 6 = 4,  path : 1 -- 6

From 2 to 1 = 2,  path : 2 -- 1
From 2 to 2 = 0,  path : 2
From 2 to 3 = 3,  path : 2 -- 3
From 2 to 4 = 1,  path : 2 -- 4
From 2 to 5 = 4,  path : 2 -- 4 -- 5
From 2 to 6 = 4,  path : 2 -- 6

From 3 to 1 = 5,  path : 3 -- 2 -- 1
From 3 to 2 = 3,  path : 3 -- 2
From 3 to 3 = 0,  path : 3
From 3 to 4 = 4,  path : 3 -- 2 -- 4
From 3 to 5 = 2,  path : 3 -- 5
From 3 to 6 = 7,  path : 3 -- 2 -- 6

From 4 to 1 = 3,  path : 4 -- 2 -- 1
From 4 to 2 = 1,  path : 4 -- 2
From 4 to 3 = 4,  path : 4 -- 2 -- 3
From 4 to 4 = 0,  path : 4
From 4 to 5 = 3,  path : 4 -- 5
From 4 to 6 = 5,  path : 4 -- 2 -- 6

From 5 to 1 = 6,  path : 5 -- 4 -- 2 -- 1
From 5 to 2 = 4,  path : 5 -- 4 -- 2
From 5 to 3 = 2,  path : 5 -- 3
From 5 to 4 = 3,  path : 5 -- 4
From 5 to 5 = 0,  path : 5
From 5 to 6 = 8,  path : 5 -- 4 -- 2 -- 6

From 6 to 1 = 4,  path : 6 -- 1
From 6 to 2 = 4,  path : 6 -- 2
From 6 to 3 = 7,  path : 6 -- 2 -- 3
From 6 to 4 = 5,  path : 6 -- 2 -- 4
From 6 to 5 = 8,  path : 6 -- 2 -- 4 -- 5
From 6 to 6 = 0,  path : 6
*/
