#include<bits/stdc++.h>
using namespace std;

bool customSort(int a, int b)
{
    string s1 = to_string(a);
    string s2 = to_string(b);
    return s1 + s2 > s2 + s1;
}


class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
       sort(nums.begin(), nums.end(), customSort);
       string s = "";
       for(auto it: nums)
       {
           s += to_string(it);
       }
       if(s[0] == '0')
       {
           return "0";
       }
         return s;
    }
};