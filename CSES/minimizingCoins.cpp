#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for (int i = a; i < b; i++)
#define ll long long
#define vi vector<int>
#define vll vector<ll>

int main(){
    int n,target;
    cin>>n>>target;
    vi c(n);
    for(int &it : c) cin>>it;
    vi dp(target+1,1e9+1);
    dp[0] = 0;
    fr(i,1,target+1){
        for(int j=0;j<n;j++){
            if(i-c[j]>=0){ 
                dp[i] = min(dp[i],dp[i-c[j]]+1); // dp[i-c[j]]+1 is the number of coins required to make sum i-c[j] + 1 coin of value c[j]
            }
        }
    }
    if(dp[target]==1e9+1) cout<<-1;
    else cout<<dp[target];
}