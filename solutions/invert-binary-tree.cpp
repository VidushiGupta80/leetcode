//Invert Binary Tree -> 06/07/2020 12:25
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
    
    void invert(TreeNode* root)
    {
        if(isLeaf(root))
            return;
        
        TreeNode* temp = NULL;
        // if(root->left)
            temp = root->left;
        // if(root->right)
           root->left = root->right;
        root->right = temp;
        
        if(root->left)
            invert(root->left);
        if(root->right)
            invert(root->right);
        
        return;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        invert(root);
        return root;
    }
};
