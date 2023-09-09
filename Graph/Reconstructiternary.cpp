#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string,vector<string>>graph;

        for (const auto ticket : tickets){
            string departure = ticket[0];
            string arrival = ticket[1];
            graph[departure].push_back(arrival);
        }

        for (auto &destinations : graph){
            sort(destinations.second.begin() , destinations.second.end());
        }

        stack<string>st;
        vector<string>circuit;
        st.push("JFK");

        while(!st.empty()){
            auto curr = st.top();

            if(graph.find(curr) == graph.end() || graph[curr].empty()){ // if we have reached a dead end or we have no more outgoing edges
                circuit.push_back(curr);
                st.pop();
            } else {
                string next = graph[curr][0];   // take the first edge
                graph[curr].erase(graph[curr].begin()); // remove the edge
                st.push(next);
            }
        }
        reverse(circuit.begin() , circuit.end());
        return circuit;
    }
};

/*

Eulerian Circuit {
    src -> extra outdegree  
    dest -> extra indegree
    other nodes -> indegree == outdegree

    Eulerian Path is a path in a graph that visits every edge exactly once. Eulerian Circuit is an Eulerian Path that starts and ends on the same vertex
}

characteristics of Eulerian Path {
    1. Undirected graph
    2. All vertices with non-zero degree are connected
    3. All vertices have even degree
}
 
Algorithm {
    1. Find the number of vertices with odd degree. Let this number be n.
    2. If n is greater than 2, then no Eulerian path exists. If n is 0, then all Eulerian cycles and paths are possible. If n is 2, then a Eulerian path exists
    3. If n is 1, then there is no Eulerian path
    4. Let u be one vertex with odd degree. If u is connected to all other vertices, then print Eulerian Path starts with u. Else print Eulerian Path starts with v
}

Connect Me - Avijit Sen
*/