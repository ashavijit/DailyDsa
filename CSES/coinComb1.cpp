#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for (int i = a; i < b; i++)
#define ll long long
#define vi vector<int>
#define vll vector<ll>

static const int MOD = 1e9+7;

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> vc(n);
    fr(i, 0, n) cin >> vc[i];

    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    fr(i, 1, target + 1)
    {
        fr(j, 0, n)
        {
            if (i >= vc[j])
            {
                dp[i] = (dp[i] + dp[i - vc[j]]) % MOD;
            }
        }
    }

    cout << dp[target] << endl;
    return 0;
}