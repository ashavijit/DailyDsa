#include<istream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int total = 0;
        int n = ratings.size();
        vector<int>l2r(n,1);
        vector<int>r2l(n,1);
        for(int i=0;i<n;i++){
            if(ratings[i] > ratings[i-1]){
                l2r[i] = l2r[i-1]+1;
            }
        }
        for(int i =n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1]){
                r2l[i] = r2l[i]+1;
            }
        }
        for(int i=0;i<n;i++){
            total+=max(l2r[i],r2l[i]);
        }
        return total;
    }
};
