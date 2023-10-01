#include<bits/stdc++.h>
using namespace std;

#define do_not_sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define speedup { \
    do_not_sync \
    cin.exceptions(cin.failbit); \
}

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_set<int> s;
        for(int num : nums)
        {
            if(s.find(num) != s.end()) // found
                return num;
            s.insert(num);
        }
        return -1;
    }
};