#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    class tuple{
    public:
        int node;
        int mask;
        int cost;
        tuple(int node,int mask,int cost){
            this->node = node;
            this->mask = mask;
            this->cost = cost;
        }
    };
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n = graph.size();
        queue<tuple>q;
        set<pair<int,int>>st;
        int totalNodes = (1<<n) -1;

        for(int i=0;i<n;i++){
            int curr_mask =(1<<i);
            tuple curr_node(i,curr_mask,1);
            q.push(curr_node);
            st.insert({i,curr_mask});
        }
        while(!q.empty()){
            tuple curr = q.front();
            q.pop();
            if(curr.mask == totalNodes){
                return curr.cost-1;
            }
            for(auto &adj : graph[curr.node]){
                int vis = curr.mask;
                vis |= (1<<adj);
                tuple thisNode(adj,vis,curr.cost+1);

                if(st.find({adj,vis}) == st.end()){
                    st.insert({adj,vis});
                    q.push(thisNode);
                }
            }
        }
    return -1;
    }
};