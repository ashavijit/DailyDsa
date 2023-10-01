#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for (int i = a; i < b; i++)
int MOD = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

vi ar[100001];
bool vis[100001];

void dfs(int node)
{
    vis[node] = 1;
    for (auto child : ar[node])
    {
        if (vis[child] == 0)
        {
            dfs(child);
        }
    }
}

int main()
{
    int n, m, a, b;
    vi ans;

    cin >> n >> m; 

    fr(i, 0, m)
    { 
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    fr(i, 1, n + 1)
    { 
        if (vis[i] == 0)
        {
            dfs(i);
            ans.push_back(i);
        }
    }

    cout << ans.size() - 1 << endl;
    for (int i = 1; i < ans.size(); i++)
    { 
        cout << ans[i - 1] << " " << ans[i] << endl;
    }

    return 0; 
}
