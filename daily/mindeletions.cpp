#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletion(vector<int> &nums)
    {
        int n = nums.size();
        int deletions = 0;
        int ans = 0;
        for(int i=0;i<n-1;i++){
            if(nums[i] == nums[i+1] && (i-deletions) % 2 == 0){
                deletions++;
            }
        }
        return deletions+(n-deletions)%2;
    }
};