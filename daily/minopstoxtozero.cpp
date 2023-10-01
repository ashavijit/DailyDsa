#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int total = accumulate(nums.begin(),nums.end(),0);
        int rem = total - x;
        if (rem < 0) return -1;
        if(rem == nums.size()) return nums.size();

        int curr_sum=0,left=0,maxS=0;
        for(int r=0;r<nums.size();r++){
            curr_sum+=nums[r];

            while(curr_sum > rem){
                curr_sum-=nums[left++];
            }

            if(curr_sum == rem){
                maxS=max(maxS,r-left+1);
            }   
        }
        return (maxS==-1) ? -1 : nums.size()-maxS;  
    }
};