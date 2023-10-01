#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define vi vector<int>
#define fr(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
#define mp map<int, int>

class Solution
{
public:
    int countPairs(vector<vector<int>> &c, int k)
    {
        map<vector<int>, int> m;
        for(auto it : c){
            m[it]++;
        }

        ll ans = 0;
        if(k == 0){
            for (auto it : m){
                ans+=it.second*(it.second -1) /2; // n(n-1)/2
            }
            return ans;
        } else {
            for(auto &it : m){
                fr(j,0,k+1){
                    vi(temp) = {it.first[0] ^ j , it.first[1] ^ (k-j)};
                    if(m.find(temp) != m.end()){
                        ans+=m[temp]*it.second;
                    }
                }
            }
        }
        return ans/2;
    }
};