#include<bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for (int i = a; i < b; i++)
int MOD = 1e9 + 7;
typedef long long ll;
#define pi pair<int, int>
typedef vector<int> vi;
#define mincost INT_MAX

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<vector<int>>>adj(n);

        for (auto it : flights){
            int from = it[0];
            int to = it[1];
            int cost = it[2];
            adj[from].push_back({to,cost});
        }

        queue<vector<int>>q;
        q.push({src,0,-1});

        while(!q.empty()){
            vector<int>curr = q.front();
            q.pop();
            int currc = curr[0];
            int currcost = curr[1];
            int currK = curr[2];

            if (currc == dst){
                return min(mincost,currcost);
            }

            for (auto it : adj[currc]){
                if(currK+1 < k && currcost + it[1] < mincost){
                    q.push({it[0],it[1],currK+1});
                }
            }
        }
        return mincost == INT_MAX ? -1 : mincost;
    }
};