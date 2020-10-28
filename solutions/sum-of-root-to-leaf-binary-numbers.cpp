//Sum of Root To Leaf Binary Numbers</a -> 08/21/2020 18:10
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
bool isLeaf(TreeNode* root){
    return root->left == NULL && root->right == NULL;
}
void dfs(int num, int& sum, TreeNode* root)
{
    if(root == NULL)
        return;
    num = num * 2 + root->val;
    if(isLeaf(root))
    {
        sum += num;
        return;
    }
    if(root->left)
        dfs(num, sum, root->left);
    if(root->right)
        dfs(num, sum, root->right);
    return;
    
}
    
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        dfs(0, sum, root);
        return sum;
    }
};
