//Maximum Depth of Binary Tree -> 06/04/2020 18:30
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
class Solution {
    
    
    
    private:
    bool isLeaf(TreeNode* root)
    {
        if(root->left == NULL && root->right == NULL)
            return true;
        return false;
    }
    
    int findDepth(TreeNode* root)
    {
        if(isLeaf(root))
            return 1;
        
        int leftVal = 0, rightVal = 0;
        if(root->left != NULL)
            leftVal = findDepth(root->left);
        if(root->right != NULL)
            rightVal = findDepth(root->right);
        // maximum = max(maximum, leftVal + rightVal);
        
        return 1 + max(leftVal, rightVal);
            
    }
    
public:
    int maxDepth(TreeNode* root) {
        // maximum = INT_MIN;
        if(root == NULL)
            return 0;
       
        int ans = findDepth(root);
        // ans--;
        // return max(maximum, ans);
        return ans;
    }
};
