#include<bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for (int i = a; i < b; i++)
int MOD = 1e9 + 7;
typedef long long ll;
#define pi pair<int, int>
typedef vector<int> vi;
#define mincost INT_MAX

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
     vi vis(26,0);
     vi freq(26,0);
     int n = s.length();
     string ans = "";
     fr(i,0,n){
        freq[s[i] - 'a']++;
     }

     fr(i,0,n){
        freq[s[i]-'a']--;
        if(!vis[s[i]-'a']){
            while(ans.size() > 0 && ans.back() > s[i] && freq[ans.back()-'a']>0){ // chec1k if the last element is greater than the current element and if the last element has more frequency
                vis[ans.back() -'a'] =0;
                ans.pop_back();
            }
            ans+=s[i];
            vis[s[i] -'a'] =1;
        }
     }
     return ans;
    }
};

class Solution
{
public:
    string smallestSubsequence(string s)
    {
        vi vis(26,0);
        vi freq(26,0);
        int n = s.length();
        string ans = "";
        fr(i,0,n){
            freq[s[i] - 'a']+=1;
        }

        fr(i,0,n){
            if(!vis[s[i] - 'a']){
                while(ans.size() > 0 && ans.back() > s[i] && freq[ans.back()-'a'] > 0){
                    vis[ans.back() - 'a'] +=1;
                    ans.pop_back();
                }
                ans+=s[i];
                vis[s[i] - 'a']=1;
            }
        }
        return ans;
    }
};