#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
//    bool mySort(string a,string b){
//         return a.length() < b.length();
//     }
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(),words.end(),[](string a,string b){return a.length() < b.length();});
        map<string,int>m;
        int res = 0 ;
        for(string word : words){
            int longest = 0 ;
            for(int i=0;i<word.length();i++){
                string newS = word.substr(0,i) + word.substr(i+1,word.length()+1); // removing the ith character ex     abc -> ac
                longest = max(longest,m[newS]+1); // longest chain of newS + 1 ex abc -> ac -> a
            }
            m[word] = longest;
            res = max(res,longest); // longest chain of word 
        }
        return res;
    }
};