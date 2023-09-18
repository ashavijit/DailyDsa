#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string,vector<string>>g;
        for (const auto ticket : tickets){
            string dept = ticket[0];
            string arv = ticket[1];
            g[dept].push_back(arv);
        }

        for( auto &it : g){
            sort(it.second.begin(),it.second.end());
        }

        stack<string>st;
        vector<string>circuit;

        st.push("JFK");

        while(!st.empty()){
            auto curr = st.top();
            if(g.find(curr) == g.end() || g[curr].empty()){
                circuit.emplace_back(curr);
                st.pop();
            } else {
                string next = g[curr][0];
                g[curr].erase(g[curr].begin());
                st.push(next);
            }
        }
        reverse(circuit.begin(),circuit.end());
        return circuit;

    }
};