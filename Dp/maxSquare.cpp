#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &mat)
    {
        if(mat.size()==0)
            return 0;

        int n = mat.size();
        int m = mat[0].size();
        int size = 0;
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0)
                    dp[i][j] = mat[i][j]-'0';
                else if(mat[i][j]=='0')
                    dp[i][j] = 0;
                else if(mat[i][j]=='1')
                    dp[i][j] = min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]}) + 1;
                size = max(dp[i][j],size);
            }
        }
        return size*size;
    }
};