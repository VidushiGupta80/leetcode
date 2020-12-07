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
bool HasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL){
            if(sum - root->val == 0)
                return true;
            else 
                return false;
        }
        bool right = false;
        bool left = HasPathSum(root->left, sum - root->val);
        if(!left)
            right = HasPathSum(root->right, sum - root->val);
        return left || right;
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        return HasPathSum(root, sum);
    }
};