#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a, b) for (int i = a; i < b; i++)
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

vector<int> tree[200001];

void solve(int src, int par, vector<int> &ans)
{
    int subords = 0;
    for (int child : tree[src])
    {
        if (child != par)
        {
            solve(child, src, ans);
            subords += (1 + ans[child]);
        }
    }
    ans[src] = subords;
}

int main()
{
    fast_io;
    ll t, n, m, x, i, j, k, q;
    // cin >> t;
    t = 1;
    while (t--)
    {
        cin >> n;
        vector<int> ans(n + 1);
        fr(2, n + 1)
        {
            cin >> x;
            tree[x].push_back(i);
            tree[i].push_back(x);
        }
        solve(1, 0, ans);
        fr(1, n + 1)
                cout
            << ans[i] << ' ';
    }
    return 0;
}