#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &mat)
    {
        if(mat.empty()) return 0;
        int curr_size = 0;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j] == '1'){
                    dp[i][j] = min({dp[i-1][j-1] ,dp[i][j-1],dp[i-1][j]})+1;
                    curr_size=max(curr_size,dp[i][j]);
                }
            }
        }
        return curr_size*curr_size;
    }
};