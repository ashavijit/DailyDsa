#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for (int i = a; i < b; i++)
int MOD = 1e9 + 7;

int main(){
    int n ;
    cin>>n;
    vector<int>dp(n+1,1e9);
    dp[0] = 0;
    fr(i,1,n+1){
        for(char ch : to_string(i)){
            dp[i] = min(dp[i] , dp[i-(ch-'0')]+1);
        }
    }
    cout<<dp[n]<<endl;
}