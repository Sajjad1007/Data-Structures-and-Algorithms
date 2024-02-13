#include <iostream>
#include <queue>

#define INF 1e9

using namespace std;

int Move[9][9];
int dr[] = {0, -2, -2, -1, -1, 1, 1, 2, 2};            // Direction array
int dc[] = {0, -1, 1, -2, 2, -2, 2, -1, 1};

struct node
{
    int r, c;
} parent[9][9];

void init()
{
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            Move[i][j] = INF;
        }
    }
    return;
}

bool valid(int r, int c)
{
    if(r >= 1 && r <= 8 && c >= 1 && c <= 8)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void bfs(int sr, int sc)
{
    queue <node> q;
    init();
    Move[sr][sc] = 0;
    parent[sr][sc] = {sr, sc};
    q.push({sr, sc});

    while(!q.empty())
    {
        int r = q.front().r;
        int c = q.front().c;
        q.pop();

        for(int i = 1; i <= 8; i++)
        {
            int nr = r+dr[i];
            int nc = c+dc[i];

            if(Move[nr][nc] == INF && valid(nr, nc))
            {
                Move[nr][nc] = Move[r][c]+1;
                parent[nr][nc] = {r, c};
                q.push({nr, nc});
            }
        }
    }
    return;
}

void print_path(int r, int c)
{
    node p = parent[r][c];
    if(r == p.r && c == p.c)
    {
        printf("(%d, %d)", r, c);
    }
    else
    {
        print_path(p.r, p.c);
        printf(" -- (%d, %d)", r, c);
    }
    return;
}

int main()
{
    int qr, qc, kr, kc;
    cout << "Knight's position : ";
    cin >> kr >> kc;
    cout << "Queen's  position : ";
    cin >> qr >> qc;

    bfs(kr, kc);
    cout << "\nThe knight needs " << Move[qr][qc] << " moves to capture the queen\n";
    cout << "The path : ";
    print_path(qr, qc);
    cout << "\n";
    return 0;
}

/*
Knight's position : 1 1
Queen's  position : 3 3

The knight needs 4 moves to capture the queen
The path : (1, 1) -- (2, 3) -- (3, 1) -- (1, 2) -- (3, 3)
*/
