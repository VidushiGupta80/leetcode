//Path Sum III -> 08/08/2020 23:58
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

int ans;

void dfs(TreeNode* root, int sum, long long curr, map<TreeNode*, bool>& cache)
{
    // if(curr == sum)
    //     ans++;
    
    // if(cache.find(make_pair(root, curr)) != cache.end())
    //     return;    
    long long total = root->val;
    if(cache.find(root) == cache.end() && total == sum)
        ans++;
    if(total + curr == sum)
        ans++;
    if(root->left)
    {
        dfs(root->left, sum, total + curr, cache);
        if(cache.find(root) == cache.end())
            dfs(root->left, sum, total, cache);
    }
    if(root->right)
    {
        dfs(root->right, sum, total + curr, cache);
        if(cache.find(root) == cache.end())
            dfs(root->right, sum, total ,cache);
    }
    cache[root] = true;
    return;
}

class Solution {

public:
    int pathSum(TreeNode* root, int sum) {
        ans = 0;
        if(root == NULL)
            return ans;
        map<TreeNode*, bool> cache;
        if(root->val == sum)
            ans++;
        if(root->left)
            dfs(root->left, sum, root->val,cache);
        if(root->right)
            dfs(root->right, sum, root->val, cache);
        return ans;
    }
};
