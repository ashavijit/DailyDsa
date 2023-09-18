#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(int m, int n, int row, int col)
    {
        return (row >= 0 && col >= 0 && row < m && col < n);
    }

    int dfs(int m, int n, int row, int col, int N, vector<vector<vector<int>>> &dp)
    {
        if (N < 0)
            return 0;
        if (!check(m, n, row, col))
        {
            return 1;
        }
        if (dp[N][row][col] != -1)
            return dp[N][row][col];
        int moves = 0;
        const int mod = 1000000007;                                 
        moves = (moves + dfs(m, n, row + 1, col, N - 1, dp)) % mod; 
        moves = (moves + dfs(m, n, row - 1, col, N - 1, dp)) % mod; 
        moves = (moves + dfs(m, n, row, col + 1, N - 1, dp)) % mod;
        moves = (moves + dfs(m, n, row, col - 1, N - 1, dp)) % mod; 
        dp[N][row][col] = moves;
        return moves;
    }

    int findPaths(int m, int n, int N, int i, int j)
    {
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m, vector<int>(n, -1)));
        return dfs(m, n, i, j, N, dp);
    }
};
