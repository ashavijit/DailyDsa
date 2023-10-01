#include<bits/stdc++.h>
using namespace std;

#define ul unsigned long
const int MOD = 1000000007;

ul calMod(ul x,int y){
    ul res = 1;
    while(y>0){ 
        if(y&1){
            res = (res*x)%MOD; // this line means  ex ; 2^5 = 2^1 * 2^4
        }
        x = (x*x)%MOD;
        y>>=1; // y = y/2
    }
    return res;
}



class Fancy
{
public:
    vector<ul>seq;
    ul increment = 0;
    ul mult = 1;
    Fancy()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    void append(int val)
    {
        val = (val - increment + MOD) % MOD;
        val = (val * calMod(mult,MOD-2))% MOD;
        seq.push_back(val);
    }

    void addAll(int inc)
    {
        increment = (increment+inc)%MOD;
    }

    void multAll(int m)
    { 
        increment = (increment*m) % MOD;
        mult = (mult*m) % MOD;
    }

    int getIndex(int idx)
    {
        if(idx>= seq.size()){
            return -1;
        } else {
            return (seq[idx]*mult+increment)%MOD;
        }
    }
};