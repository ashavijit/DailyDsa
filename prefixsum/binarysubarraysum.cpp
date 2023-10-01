#include<bits/stdc++.h>
using namespace std;

class Solution
{

private:
    int cntSubArr(vector<int> &nums,int sum){
        if(sum < 0) return 0;
        int ps =0,j=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            ps+=nums[i];
            while(ps>sum){
                ps-=nums[j++];
            }
            cnt+=(i-j+1);
        }
        return cnt;

    }
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return cntSubArr(nums, goal) - cntSubArr(nums, goal - 1); // cntSubArr(nums,goal) is the number of subarrays with sum <= goal - cntSubArr(nums,goal-1) is the number of subarrays with sum < goal
    }
};