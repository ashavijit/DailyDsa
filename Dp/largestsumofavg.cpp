#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double helper(vector<int>&nums,int k ,int i, vector<vector<double>>&dp) {
        if(i>= nums.size()) return 0;
        if(k == 0) return INT_MIN;
        if(dp[i][k] != -1) return dp[i][k];
        double sum =0;
        double _max = INT_MIN;
        for(int j=i;j<nums.size();j++){
            sum+=nums[j];

            _max=max(_max ,sum / (j-i+1) + helper(nums,k-1,j+1,dp));
        }
    return dp[i][k] = _max;
    }
    double largestSumOfAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<double>>dp(n,vector<double>(k+1,-1));
        return helper(nums,k,0,dp);
    }
};