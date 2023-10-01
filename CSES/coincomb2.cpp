#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for (int i = a; i < b; i++)
int MOD = 1e9+7;
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> vc(n);
    fr(i, 0, n) cin >> vc[i];

    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
    dp[0][0] = 1;
    fr(i,1,n+1){
        fr(j,0,target+1){
            dp[i][j] = dp[i-1][j];
            int avl = j - vc[i-1];
            if(avl >= 0){
               dp[i][j] =(dp[i][j] + dp[i][avl]) %MOD;
            }
        }
    }

    cout << dp[n][target]<< endl;
    return 0;
}