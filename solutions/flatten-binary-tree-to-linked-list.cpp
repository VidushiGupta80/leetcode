//Flatten Binary Tree to Linked List -> 08/27/2020 17:10
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
public:
    TreeNode* tmp = NULL;
    void flatten(TreeNode* root) {
        if(root==NULL)  return;
        
        flatten(root->right);
        flatten(root->left);
  
        root->right=tmp;
        root->left=NULL;
        
        tmp=root;
    }
};