#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define endl "\n"
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
typedef pair<int, int> pi;

class DSU{
    public:
    vector<int>rank,parent;
    DSU(int n){
        rank.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int findPar(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = findPar(parent[x]); // path compression
    }

    bool unionByRank(int u ,int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if(ulp_u == ulp_v) return 0;

        // comparing the ranks 
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u] +=1;
        }
        return 1;

    }
};

class Solution
{
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>> &queries)
    {
        DSU ds(n+1);
        for(int i=threshold+1;i<=n;i++){ 
            for(int j=2*i;j<=n;j+=i){ // union of all the multiples of i
                ds.unionByRank(i,j);
            }
        }

        vector<bool>ans;
        for(auto q:queries){
            int u = q[0];
            int v = q[1];
            if(ds.findPar(u) == ds.findPar(v)){
                ans.push_back(1);
            } else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};
