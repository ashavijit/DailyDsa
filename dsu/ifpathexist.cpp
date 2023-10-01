#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int>par;
    int findPar(int x){
        if( x== par[x]){
            return x;
        }
        return par[x] = findPar(par[x]);
    }
    int isSame(int x ,int y){
        int ulp_x = findPar(x);
        int ulp_y = findPar(y);
        par[ulp_x] = ulp_y;
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            isSame(u,v);
        }
        return findPar(source) == findPar(destination);
    }
};