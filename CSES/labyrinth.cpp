#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

const int MAX_N = 1000;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool vis[MAX_N][MAX_N];
char grid[MAX_N][MAX_N], par[MAX_N][MAX_N], ans[MAX_N * MAX_N];
int N, M, sx, sy, ex, ey, dist[MAX_N][MAX_N];
queue<pii> Q;

#define isInside(x, y) (0 <= (x) && (x) < N && 0 <= (y) && (y) < M)

void bfs()
{
    vis[sx][sy] = true;
    Q.push({sx, sy});
    while (!Q.empty())
    {
        pii P = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = P.first + dx[i];
            int ny = P.second + dy[i];
            if (isInside(nx, ny) && !vis[nx][ny])
            {
                if (i == 0)
                    par[nx][ny] = 'D';
                else if (i == 1)
                    par[nx][ny] = 'U';
                else if (i == 2)
                    par[nx][ny] = 'R';
                else if (i == 3)
                    par[nx][ny] = 'L';
                dist[nx][ny] = dist[P.first][P.second] + 1;
                vis[nx][ny] = true;
                Q.push({nx, ny});
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                sx = i;
                sy = j;
            }
            else if (grid[i][j] == 'B')
            {
                ex = i;
                ey = j;
            }
            if (grid[i][j] == '#')
            {
                vis[i][j] = true;
            }
        }
    }

    bfs();

    if (!vis[ex][ey])
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl
         << dist[ex][ey] << endl;
    pii P = {ex, ey};
    for (int i = dist[ex][ey]; i > 0; i--)
    {
        ans[i] = par[P.first][P.second];
        if (ans[i] == 'D')
            P = {P.first - 1, P.second};
        else if (ans[i] == 'U')
            P = {P.first + 1, P.second};
        else if (ans[i] == 'R')
            P = {P.first, P.second - 1};
        else if (ans[i] == 'L')
            P = {P.first, P.second + 1};
    }
    for (int i = 1; i <= dist[ex][ey]; i++)
    {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
