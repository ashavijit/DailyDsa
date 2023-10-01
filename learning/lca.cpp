#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int LOGN = 20;
vector<int> adj[N];
int par[N];
int lvl[N];
int LCA[N][LOGN];



int lca (int a , int b) {
    if(lvl[b] < lvl[a])  swap(a,b);
    int d = lvl[b] - lvl[a];

    while(d > 0){
        b = par[b];
        d--;
    }

    if ( a == b ) return a;

    while(par[a] != par[b]){
        a = par[a];
        b = par[b];
    }
    return par[a];
}

int lcaUsingBinaryLifting(int a , int b){
    if(lvl[b] < lvl[a]){
        swap(a,b);
    }
    int d = lvl[b] - lvl[a];
    while(d > 0){
        int i = log2(d);
        b = LCA[b][i];
        d-=(1<<i); // reducing what is already jumped
    }

    if (a==b) return a;

    // while(LCA[a][0] != LCA[b][0]){ Because this is taking O(n) time
    //     a = LCA[a][0];
    //     b = LCA[b][0];
    // }

    for(int i = LOGN ; i>=0;i--){
        if((LCA[a][i] != -1) && (LCA[a][i] != LCA[b][i])){
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }
    return LCA[a][0];
}