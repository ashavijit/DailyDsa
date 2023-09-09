#include<header.h>

#include <vector>
#include <cstring>

class TreeAncestor
{
    static const int MAX_NODES = 100000;
    static const int MAX_LOG = 20;

    int ancestor[MAX_NODES][MAX_LOG];

    void dfs(const vector<vector<int>> &tree, int node, int parent)
    {
        ancestor[node][0] = parent;
        for (int i = 1; i < MAX_LOG; i++)
        {
            if (ancestor[node][i - 1] != -1)
                ancestor[node][i] = ancestor[ancestor[node][i - 1]][i - 1]; 
        }
        for (int child : tree[node])
        {
            if (child != parent)
            {
                dfs(tree, child, node);
            }
        }
    }

public:
    TreeAncestor(int n, const vector<int> &parent)
    {
        memset(ancestor, -1, sizeof ancestor);
        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++)
        {
            tree[parent[i]].push_back(i);
        }

        dfs(tree, 0, -1); // 0 is the root
    }

    int getKthAncestor(int node, int k)
    {
        if (k < 0)
            return -1;
        for (int i = 0; i < MAX_LOG; i++) // 2^i th ancestor of node is ancestor[node][i]
        {
            if ((k >> i) & 1) // if k has ith bit set ex 5 = 101, 5 >> 0 = 101, 5 >> 1 = 10, 5 >> 2 = 1
            {
                node = ancestor[node][i]; // 5th ancestor = 4th ancestor of 4th ancestor
                if (node == -1) // if node is root, 5th ancestor will be -1
                    return -1;
            }
        }
        return node;
    }
};


/*
(k>>i)  & 1 signifies if ith bit is set in k for example 5 = 101, 5>>0 = 101, 5>>1 = 10, 5>>2 = 1  so 5>>0 & 1 = 1, 5>>1 & 1 = 0, 5>>2 & 1 = 1

if k = 5, node = 4, 4th ancestor of 4th anc

k = 5 = 101
i = 0, 1, 2
k>>i = 101, 10, 1
*/