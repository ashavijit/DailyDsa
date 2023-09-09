#include<tree.h>
#include<header.h>

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if(inorder.size() != postorder.size()){
            return NULL;
        }
        map<int,int>mp;
        for (int i = 0; i < inorder.size();i++){
            inorder[i] = i;
        }
        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, mp);

    }
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder,int ins , int ine , int poss ,int pose , map<int,int> &mp){
        if (ins > ine || poss > pose){
            return NULL;
        }
        TreeNode*root = new TreeNode(postorder[pose]);
        int inRoot = mp[postorder[pose]];
        int left_elem = inRoot - ins;
        root->left = helper(inorder,postorder, ins, inRoot - 1, poss, poss + left_elem - 1, mp);
        root->right = helper(inorder, postorder, inRoot + 1, ine, poss + left_elem, pose - 1, mp);
        return root;
    }
};