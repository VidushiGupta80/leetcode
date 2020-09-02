//Delete Node in a BST -> 09/02/2020 11:56
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
TreeNode* dfs(TreeNode* root, int key)
{
    if(!root)
        return NULL;
    if(root->val == key){
        if(!root->left && !root->right)
            root = NULL;
        else if(root->left){
           TreeNode* temp = root->left;
            while(temp->right)
                temp = temp->right;
            root->val = temp->val;
            root->left = dfs(root->left, temp->val);
        }
        else if(root->right){
            TreeNode* temp = root->right;
            while(temp->left)
                temp = temp->left;
            root->val = temp->val;
            root->right = dfs(root->right, temp->val);
        }
    }
    else if(root->val > key && root->left)
        root->left = dfs(root->left, key);
    else if(root->val < key && root->right)
        root->right = dfs(root->right, key);
    return root;
}
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        root = dfs(root, key);
        return root;
    }
};
