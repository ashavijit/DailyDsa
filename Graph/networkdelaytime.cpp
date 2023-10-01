#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        for(int i=1;i<n;i++){
            for(auto it : times){
                int f = it[0]; //u
                int t = it[1]; //v
                int w = it[2];

                if(dis[f] != INT_MAX && dis[f] + w < dis[t]){
                    dis[t] = dis[f]+w; 
                }
            }
        }
        int _max=0;
        for(int i=1;i<=n;i++){
            _max = max(_max,dis[i]);
        }
        return _max == INT_MAX ? -1 : _max;
    }
};