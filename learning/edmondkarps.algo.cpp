#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>capacity;
vector<vector<int>>adj;

int bfs(int s , int t ,vector<int>&parent){
    fill(parent.begin(),parent.end(),-1);
    parent[s] = -2;
    queue<pair<int,int>>q;
    q.push({s,INFINITY});

    while(!q.empty()){
        int curr = q.front().first;
        int flow = q.front().second;
        q.pop();

        for(int it : adj[curr]){
            if(parent[it] == -1 && capacity[curr][it] > 0){ // if not visited and there is a path from curr to it
                parent[it] = curr;
                int new_flow= min(flow, capacity[curr][it]); // min of the flow and the capacity of the edge
                if(it == t){ 
                    return new_flow;
                }
                q.push({it,new_flow});
            }
        }
    }
    return 0;
}

int max_flow(int s ,int t){
    int flow = 0;
    vector<int>parent(n);
    int new_flow;

    while(new_flow = bfs(s,t,parent)){ // while there is a path from s to t
        flow+=new_flow; // add the flow to the total flow
        int curr = t; // backtrack from t to s
        while(curr != s){
            int prev = parent[curr];
            capacity[prev][curr]-=new_flow; // reduce the capacity of the edge
            capacity[curr][prev]+=new_flow;     // increase the capacity of the reverse edge
            curr = prev;
        }
    }
    return flow;
}

int main(){
    int m;
    cin>>n>>m;
    capacity = vector<vector<int>>(n,vector<int>(n,0));
    adj = vector<vector<int>>(n);

    for(int i = 0 ; i < m ; i++){
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] = c;
    }

    cout<<max_flow(0,n-1);
    return 0;
}