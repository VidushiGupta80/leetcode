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
int ans;
int findSum(TreeNode* root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL){
        ans = max(ans, root->val);
        return root->val;
    }
    int left = findSum(root->left);
    int right = findSum(root->right);
    
    int res = root->val;
    ans = max(ans, res + left + right);
    res = max(res, max(left, right) + res);
    ans = max(ans, res);
    return res;
    
        
}
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        ans = root->val;
        findSum(root);
        return ans;
    }
};