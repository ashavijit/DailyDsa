#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        int m = pairs.size();
        unordered_map<int,stack<int>>adj; // this map will store the graph
        unordered_map<int,int>in;
        unordered_map<int,int>out;

        adj.reserve(m);
        in.reserve(m);
        out.reserve(m);

        for (int i=0;i<m;i++){
            int u = pairs[i][0]; // [[5,1],[4,5],[11,9],[9,4]] --> 5,4,11,9
            int v = pairs[i][1]; // [[5,1],[4,5],[11,9],[9,4]] --> 1,5,9,4
            in[v]++; // indegree of v --> 1,1,1,1
            out[u]++; //  1,1,1,1
            adj[u].push(v); // this will create a graph --> 5,4,11,9 
            /*
            Graph diagram {
                5 -> 1
                4 -> 5
                11 -> 9
                9 -> 4
            }
            */
        }
        int start = -1;
        for (auto &p: adj){
            int curr = p.first;
            if (out[curr] - in[curr] == 1){  // property of eulerian path
                start = curr;
            }
        }
        if (start == -1){
            start = adj.begin() ->first; // if no such node exists then start from any node
        }
        vector<vector<int>>ans;

        euler_path(adj,ans,start);
        reverse(ans.begin(),ans.end()); 
        return ans;
    }
    private:
        void euler_path(unordered_map<int, stack<int>> &adj, vector<vector<int>> &ans , int curr)
        {
            auto &stk = adj[curr]; // this will give the stack of the current node i.e 5,4,11,9
            while(!stk.empty()){
                int curr_elem = stk.top(); // 5,4,11,9
                stk.pop(); 
                euler_path(adj,ans,curr_elem); // 5,4,11,9  --> 1,5,4,9,11
                ans.push_back({curr,curr_elem}); // 1,5,5,4,4,9,9,11
            }
        }
};

/*
Algorithm Intutuion {
    1. Find the number of vertices with odd degree. Let this number be n.
    2. If n is greater than 2, then no Eulerian path exists. If n is 0, then all Eulerian cycles and paths are possible. If n is 2, then a Eulerian path exists
}


This Problem States that we have to find the valid arrangement of pairs such that the first element of the pair is equal to the second element of the next pair
{
    Steps{
        1. create a graph
        2. find the indegree and outdegree of each node
        3. find the start node
        4. find the eulerian path
        5. reverse the eulerian path
    }

    Eulerian path : A path in a graph that visits every edge exactly once is called an Eulerian Path. Eulerian Path is an Eulerian Path that starts and ends on the same vertex
}
*/