// #include<tree.h>
// #include<header.h>

#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#define ll long long
class Solution
{
public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        vector<int>ans;
        priority_queue<ll>pq;
        int i,n;
        queue<TreeNode*>q;
        if(root == NULL) return -1;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            ll sum =0;
            for(int i=0;i<size;i++){
                TreeNode*temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            pq.push(sum);
        }
        if (k > pq.size()) return -1;
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};


// Input: root = [1,7,0,7,-8,null,null], k = 2