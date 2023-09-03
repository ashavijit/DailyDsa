#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries)
    {
        vector<int>ans;
        for (auto it : queries){
            int curr = 0;
            int u = it[0];
            int v = it[1];
            while(u!=v){
                if (u>v){ 
                    u=u/2; 
                } else {
                    v = v/2;
                }
                curr++;
            }
        ans.push_back(curr+1); // +1 because we are not counting the root node
        }
        return ans;
    }
};

static const auto speedup = []() {  // this is for fast I/O in c+
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int main()
{
    int n = 3;
    vector<vector<int>>queries = {{5,3}, {4,7} , {2,3}};
    Solution s;
    vector<int>ans = s.cycleLengthQueries(n,queries);
    for (auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}