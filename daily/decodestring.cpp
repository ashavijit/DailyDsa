#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for (int i = a; i < b; i++)
#define frd(i, a, b) for (int i = a; i >= b; i--)
int MOD = 1e9 + 7;
typedef long long ll;
#define pi pair<int, int>
typedef vector<int> vi;
#define mincost INT_MAX
#define INF 1e9 + 7
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define endl "\n"

class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        int n = s.length();
        int size = 0;
        fr(i,0,n){
            if(isdigit(s[i])){
                size = size * s[i];
            } else {
                size +=1;
            }
        }
        frd(i,n-1,0){
            k%=size;
            if(k==0 && isalpha(s[i])){
                // return static_cast<string> ("") + s[i];
                return string("") + s[i];
            } if (isdigit(s[i])){
                int temp = s[i] - '0';
                if(size%temp == 0){
                    size/=temp;
                } else {
                    size = size/temp;
                }
            }else {
                size--;
            }
        }
        return s.substr(k,1);
    }
};