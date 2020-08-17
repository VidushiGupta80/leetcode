//Find a Corresponding Node of a Binary Tree in a Clone of That Tree -> 08/17/2020 11:28
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* ans = NULL;
   void dfs(TreeNode* cloned, TreeNode* target)
    {
        if(cloned == NULL)
            return;
        if(cloned->val != target->val && cloned->left == NULL && cloned->right == NULL)
            return;
        if(cloned->val == target->val )
           // && cloned->left == target->left 
           // && cloned->right == target->right)
        {
            ans = cloned;
            return;
        }
        
        if(cloned->left)
            dfs(cloned->left, target);
        if(ans == NULL && cloned->right)
            dfs(cloned->right, target);
        return;
        
    }
    
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        ans = NULL;
        dfs(cloned, target);
        return ans;
    }
};
