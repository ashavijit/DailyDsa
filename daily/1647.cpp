#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletions(string s)
    {
        vector<int>freq(26,0);
        unordered_set<int>st;
        for(char ch : s){
            freq[ch-'a']++;
        }
        int cnt = 0;
        for(int i=0;i<26;i++){
            while(freq[i] > 0 && st.find(freq[i]) != st.end()){
                freq[i]--;
                cnt++;
            }
            st.insert(freq[i]);
        }
        return cnt;
    }
};