#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

    bool isEven(int n){
        return n%2 == 0;
    }
    vector<int> sortArrayByParity(vector<int> &nums)
    { 
        for(int i=0,j=0;i<nums.size();j++){
                if (isEven(nums[i]))
                {
                    swap(nums[i++],j);
                }
        }
        return nums;
    }
};
