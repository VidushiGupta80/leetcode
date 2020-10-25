//Path Sum II -> 10/23/2020 20:30
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
bool isLeaf(TreeNode* root)
{
    if(root->left == NULL && root->right == NULL)
        return true;
    return false;
}
void dfs(TreeNode* root, int s, vector<int> temp, vector<vector<int> >& res, int sum)
{
    if(isLeaf(root))
    {
        if(s + root->val == sum)
        {
            temp.push_back(root->val);
            res.push_back(temp);
        }
         return;       
    }
    temp.push_back(root->val);
    if(root->left)
    {
        dfs(root->left, s + root->val, temp, res, sum);
    }
    if(root->right)
        dfs(root->right, s + root->val, temp, res, sum);
    return;
}
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int> > res;
        if(!root)
            return res;
        vector<int> temp;
        int s = 0;
        dfs(root, s, temp, res, sum);
        return res;
        
    }
};
