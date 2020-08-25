//Sum of Left Leaves -> 08/25/2020 10:24
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
bool isLeaf(TreeNode* root)
{
    if(root->left == NULL && root->right == NULL)
        return true;
    return false;
}
int dfs(TreeNode* root)
{
    if(isLeaf(root))
    {
        return root->val;
    }
    int sum = 0;
    if(root->right && !isLeaf(root->right))
       sum += dfs(root->right);
    if(root->left)
        sum += dfs(root->left);
    return sum;
}
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(isLeaf(root))
            return 0;
        
        return dfs(root);
    }
};
