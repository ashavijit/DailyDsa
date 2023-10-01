#include<bits/stdc++.h>
using namespace std;


class DSU{
    public:
    vector<int>rank,parent,size;
    DSU(int n){
        rank.resize(n+1);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i] = i;
            size[i] =i;
        }
    }
    int findUpar(int x){
        if (x == parent[x]){
            return x;
        }
        return parent[x] = findUpar(parent[x]);
    }

    bool UnionByRank(int u ,int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v) return 0;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]+=1;
        }
        return 1;
    }

    int components(){
        int cnt =0;
        for(int i=0;i<parent.size();i++){
            if(i == parent[i]) cnt+=1;
        }
        return cnt;
    }
};

class Solution
{
public:
    bool canTraverseAllPairs(vector<int> &nums)
    {
        int n = nums.size();
        DSU ds(n);

        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            int curr = nums[i];

            if((curr & 1) == 0) adj[2].push_back(i); // 2s factor
            while((curr & 1) == 0) curr =curr/2;

            for(int j=3;j*j<=curr;j+=2){ // odd factors basically primes j=3 because 2s are already done J+=i because we are only considering odd factors
                if((curr & j) == 0) adj[curr].push_back(j);
                while((curr & j) == 0) curr /= j;
            }

            if(curr > 2) adj[curr].push_back(i); // if curr is prime
        }

        for(auto it:adj){
            int x = it.first;
            for(int i=1;i<it.second.size();i++){
                ds.UnionByRank(it.second[i-1],it.second[i]);
            }
        }
        return ds.components() == 1;
    }
};