#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define vi vector<int>
#define vll vector<ll>


static const int MOD = 1e9+7;

int main(){

    int n;
    cin>>n;
    vi dp(n+1,0);
    dp[0]=1;
    fr(i,1,n+1){
        fr(j,1,7){
            if(i-j>=0){
                dp[i] = (dp[i]+dp[i-j])%MOD;
            }
        }
    }
}