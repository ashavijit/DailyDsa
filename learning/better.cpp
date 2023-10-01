#include<bits/stdc++.h>
using namespace std;

int n; // Number of vertices in the graph
vector<vector<int>> capacity; // 2D vector to store the capacity of edges
vector<vector<int>> adj; // 2D vector to represent the adjacency list of the graph

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1); // Initialize parent array with -1 (unvisited)
    parent[s] = -2; // Mark the source vertex as visited
    queue<pair<int, int>> q; // Queue to perform BFS
    q.push({s, INFINITY}); // Push the source vertex and set initial flow as INFINITY

    while (!q.empty()) {
        int curr = q.front().first; // Current vertex
        int flow = q.front().second; // Current flow
        q.pop();

        for (int it : adj[curr]) { // Iterate over neighbors of the current vertex
            if (parent[it] == -1 && capacity[curr][it] > 0) {
                // If neighbor is unvisited and there's capacity on the edge
                parent[it] = curr; // Mark the neighbor as visited
                int new_flow = min(flow, capacity[curr][it]); // Calculate new flow as minimum of current flow and edge capacity
                if (it == t) {
                    return new_flow; // If we reach the sink vertex, return the flow
                }
                q.push({it, new_flow}); // Push the neighbor and new flow into the queue
            }
        }
    }
    return 0; // If no path to the sink is found, return 0
}

int max_flow(int s, int t) {
    int flow = 0; // Initialize the total flow to 0
    vector<int> parent(n); // Create a vector to store parents in the augmenting path
    int new_flow;

    while (new_flow = bfs(s, t, parent)) { // While there's an augmenting path from source to sink
        flow += new_flow; // Add the flow of this path to the total flow
        int curr = t; // Start from the sink vertex
        while (curr != s) { // Backtrack from sink to source
            int prev = parent[curr]; // Get the parent of the current vertex
            capacity[prev][curr] -= new_flow; // Reduce the capacity of the forward edge
            capacity[curr][prev] += new_flow; // Increase the capacity of the reverse edge
            curr = prev; // Move to the parent
        }
    }
    return flow; // Return the maximum flow
}

int main() {
    int m;
    cin >> n >> m; // Read the number of vertices and edges
    capacity = vector<vector<int>>(n, vector<int>(n, 0)); // Initialize the capacity matrix with all zeros
    adj = vector<vector<int>>(n); // Initialize the adjacency list

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c; // Read an edge (u, v) with capacity c
        adj[u].push_back(v); // Add v to the adjacency list of u
        adj[v].push_back(u); // Add u to the adjacency list of v (since the graph is undirected)
        capacity[u][v] = c; // Set the capacity of the edge (u, v) to c
    }

    cout << max_flow(0, n - 1); // Find and print the maximum flow from source (0) to sink (n-1)
    return 0;
}
