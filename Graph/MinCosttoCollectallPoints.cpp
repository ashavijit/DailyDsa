#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static const int max_e = 1001;
    int par[max_e];

    int find(int a)
    {
        if (par[a] < 0)
        {
            return a;
        }
        return par[a] = find(par[a]);
    }

    void UnionByAny(int a, int b)
    {
        if (par[a] < par[b])
        {
            par[a] += par[b];
            par[b] = a;
        }
        else
        {
            par[b] += par[a];
            par[a] = b;
        }
    }

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            par[i] = -1;
        }
        vector<pair<int, pair<int, int>>> adj;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj.push_back({wt, {i, j}});
            }
        }
        sort(adj.begin(), adj.end());
        int sum = 0;
        for (int i = 0; i < adj.size(); i++)
        {
            int a = find(adj[i].second.first);
            int b = find(adj[i].second.second);
            if (a != b)
            {
                sum += adj[i].first;
                UnionByAny(a, b);
            }
        }
        return sum;
    }
};
