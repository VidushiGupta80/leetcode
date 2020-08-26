//House Robber III -> 08/26/2020 18:53
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

int dp(TreeNode* root, bool isSafe, map<pair<TreeNode*, bool>, int>& cache)
{
    if(!root)
        return 0;
    
    if(cache.find(make_pair(root, isSafe)) != cache.end())
        return cache[make_pair(root, isSafe)];
    int ans = 0;
    if(isSafe)
    {
        int maxLT = 0, maxLF = 0, maxRT = 0, maxRF = 0;
        if(root->left)
        {
            maxLT = dp(root->left, true, cache);
            maxLF = dp(root->left, false, cache);
        }
        if(root->right)
        {
            maxRT = dp(root->right, true, cache);
            maxRF = dp(root->right, false, cache);
        }
        ans = max(maxLT + maxRT, root->val + maxLF + maxRF);
    }
    else if(!isSafe)
    {
        int l = 0, r = 0;
        if(root->left)
            l = dp(root->left, true, cache);
        if(root->right)
            r = dp(root->right, true, cache);
        ans = l + r;
    }
    return cache[make_pair(root, isSafe)] = ans;
}
public:
    int rob(TreeNode* root) {
        map<pair<TreeNode*, bool>, int> cache;
        return dp(root, true, cache);
    }
};
