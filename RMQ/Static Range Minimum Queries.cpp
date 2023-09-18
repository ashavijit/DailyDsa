#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int LOG = 17;
int a[N];
int dp[N][LOG];
int bin_log[N];

// Function to precompute logarithmic values for binary indexing.
void precomputeLog(int n)
{
    bin_log[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        bin_log[i] = bin_log[i / 2] + 1;
    }
}

// Function to build the sparse table for range minimum queries.
void buildSparseTable(int n)
{
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = a[i];
    }

    for (int k = 1; (1 << k) <= n; k++)
    {
        for (int i = 0; i + (1 << k) <= n; i++)
        {
            dp[i][k] = min(dp[i][k - 1], dp[i + (1 << (k - 1))][k - 1]);
        }
    }
}

// Function to perform a range minimum query.
int query(int L, int R)
{
    int len = R - L + 1;
    int k = bin_log[len];
    return min(dp[L][k], dp[R - (1 << k) + 1][k]);
}

int main()
{
    int n;
    cin >> n;

    // Input the array elements.
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Precompute logarithmic values and build the sparse table.
    precomputeLog(n);
    buildSparseTable(n);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int L, R;
        cin >> L >> R;

        // Perform a range minimum query and print the result.
        cout << query(L, R) << "\n";
    }

    return 0;
}
