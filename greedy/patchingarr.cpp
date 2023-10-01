#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        int p = nums.size();
        if(p == n){
            return 0;
        }
        int count = 0;
        long long int sum = 0;
        int i = 0;
        while(sum < n)
        {
            if(i < p && nums[i] <= sum + 1)
            {
                sum += nums[i];
                i++;
            }
            else
            {
                sum += sum + 1;
                count++;
            }
        }
        return count;
    }
};