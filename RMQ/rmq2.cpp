#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int LOG = 17;
int a[N];
int table[N][LOG];
int bin_log[N];


void build(int n){
    for(int i=0;i<n;i++){
        table[0][i] = a[i];
    }

    for(int k=1; (1<<k) <=n;k++){
        for(int i=0;i+(1<<k)<= n;i++){
            table[i][k] = min(table[i][k-1] , table[i+ 1<<(k-1)][k-1]); // 1<<k = 2^k
        }
    }
}

int query (int l ,int r){
    int len = r-l+1;
    int k = log2(len);
    return min(table[l][k] , table[r-(1<<k)+1][k]);
}

// RMQ using sparse table

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(n);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(l,r)<<endl;
    }
    return 0;
}