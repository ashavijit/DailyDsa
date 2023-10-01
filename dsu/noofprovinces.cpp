#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
        vector<int>rank,parent,size;
        DisjointSet(int n){
            rank.resize(n+1);
            parent.resize(n+1);
            size.resize(n+1);

            for(int i=0;i<=n;i++){
                parent[i] = i;
                size[i]=i;
            }
        }

        int findUpar(int x){
            if(x == parent[x]){
                return x;
            }

            return parent[x] = findUpar(parent[x]);
        }

        bool unionByRank(int u ,int v){
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);

            if(ulp_u == ulp_v){
                return 0;
            } 

            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if (rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        bool UnionBySize(int u,int v){
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);

            if (ulp_u == ulp_v)
            {
                return 0;
            }

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
            return 1;
        }
};

// class Solution
// {
// public:
//     int findCircleNum(vector<vector<int>> &adjList)
//     {
//         int V = adjList.size();
//         DisjointSet ds(V);
//         int cnt=0;
//         for(int i=0;i<V;i++){
//             for(int j=0;j<V;j++){
//                 if(adjList[i][j] == 1){
//                     ds.UnionBySize(i,j);
//                 }
//             }
//         }
//         for(int i=0;i<V;i++){
//             if(ds.parent[i] == i){
//                 cnt+=1;
//             }
//         }
//         return cnt;
//     }
// };

class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {
        DisjointSet ds(26);
        for (auto &eq : equations)
        {
            if (eq[1] == '=')
            {
                ds.unionByRank(eq[0] - 'a', eq[3] - 'a'); // eq[1] == '=' then union will give rank to the parent
            }
        }
        for (auto &eq : equations)
        {
            if (eq[1] == '!')
            {
                if (ds.findUpar(eq[0] - 'a') == ds.findUpar(eq[3] - 'a')) // if eq[1] == '!' then findUpar will give parent of the element
                { 
                    return false;
                }
            }
        }
        return true;
    }
};
/*

 if (a==b) then a and b are in same set  (a,b) are connected
    if (a!=b) then a and b are in different set (a,b) are not connected
    if if (ds.findUpar(eq[0] - 'a') == ds.findUpar(eq[3] - 'a')) then a and b are in same set  (a,b) are connected in this case we return false
    if if (ds.findUpar(eq[0] - 'a') != ds.findUpar(eq[3] - 'a')) then a and b are in different set (a,b) are not connected

 */