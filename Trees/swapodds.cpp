#include<header.h>
#include<tree.h>
class Solution
{
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        int level = 0;
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            for (int i=0;i<size;i++){
                TreeNode*node = q.front();
                q.pop();
                if(level & 1){ // odd level : level & 1 means level is odd 13 & 1 = 1
                    node->val = ans[size-1-i]; // reverse the level ans[size-1-i] is the reverse of ans[i]
                }
                if(node->left){
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                if(node->right){
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
            }
            ans = temp;
            level++;
        }
        return root;
    }
};

// solution by avijit sen @ashavijit 



