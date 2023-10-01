#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMiddleIndex(vector<int> &nums)
    {
        int total = accumulate(nums.begin(),nums.end(),0);

        int res = 0;
        for(int i=0;i<nums.size();i++){
            total-=nums[i];
            if(res == total){
                return i;
            }
            res+=nums[i];
        }
        return -1;
    }
};