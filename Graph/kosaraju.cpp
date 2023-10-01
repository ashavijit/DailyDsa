#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node,vector<int>&vis,vector<vector<int>> &adj,stack<int>&st){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,st);
            }
        }
        st.push(node);
    }

    void helper(int node,vector<int>&vis,vector<vector<int>> adjT){
        vis[node] =1 ;
        for(auto it : adjT[node]){
            if(!vis[it]){
                helper(it,vis,adjT);
            }
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }

        vector<vector<int>> adjT(V); // initialize with empty vectors of size V
        for(int i=0;i<V;i++){
            vis[i] = 0;
            for(auto it : adj[i]){
                // i -- it 
                adjT[it].push_back(i);
            }
        }

        int cnt = 0;
        while(!st.empty()){
            int curr = st.top();
            st.pop();
            if(!vis[curr]){
                cnt+=1;
                helper(curr,vis,adjT);
            }
        }
        return cnt;
    }
};