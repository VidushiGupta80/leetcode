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
pair<bool, int> maxLength(TreeNode* root)
{
    if(root == NULL)
        return {true, 0};
    if(root->left == NULL && root->right == NULL)
        return {true, 1};
    pair<bool, int> left = maxLength(root->left);
    pair<bool, int> right = maxLength(root->right);
    
    return {left.first && right.first && abs(left.second - right.second) <= 1, max(left.second, right.second) + 1};
}
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        return maxLength(root).first;
    }
};