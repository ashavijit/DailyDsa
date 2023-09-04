#include<tree.h>
#include<header.h>

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
class Solution
{
public:
    void helper(TreeNode*root,int ans){
        if(root == NULL) return;
        helper(root->right,ans);
        root->val+=ans;
        ans = root->val;
        helper(root->left,ans);
    }
    TreeNode *bstToGst(TreeNode *root)
    {
        int ans = 0;
        helper(root,ans);
        return root;
    }
};
