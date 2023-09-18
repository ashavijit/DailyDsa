#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000;
char grid[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];

int n, m, cnt;
vector<int> dirX = {-1, 1, 0, 0};
vector<int> dirY = {0, 0, -1, 1};

bool isValid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int dx = x + dirX[i];
        int dy = y + dirY[i];
        if (isValid(dx, dy) && !vis[dx][dy] && grid[dx][dy] == '.')
        {
            dfs(dx, dy);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
