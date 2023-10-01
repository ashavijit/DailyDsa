#include<bits/stdc++.h>
using namespace std;

class Solution
{

private:
    int timer = 1;
    void dfs(int node,int par,vector<int>&vis,vector<int>adj[],int tin[],int low[],vector<vector<int>>&bridges)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer+=1;
        for(auto it : adj[node]){
            if(it == par) continue;
            if(vis[it] == 0){
                dfs(it,par,vis,adj,tin,low,bridges);
                low[node] = min(low[it],low[node]);
 
                if(low[it] > tin[node]){ // bridge found low[it] > tin[node] means there is no back edge
                    bridges.push_back({node,it});
                }
            } else{
                low[node] = min(low[node],tin[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int>adj[n];

        for (auto it : connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        int tin[n];
        int low[n];
        vector<vector<int>>bridges;
        dfs(0,-1,vis,adj,tin,low,bridges);
        return bridges;
    }
};