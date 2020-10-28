//Cousins in Binary Tree -> 08/11/2020 23:56

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
    
    pair<int, int> dp(int x, TreeNode* root, int depth, int parent)
    {
        if(root->val == x)
            return make_pair(depth, parent);
        if(!root->left && !root->right && root->val != x)
            return make_pair(-1, -1);
        pair<int, int> ans = {-1, -1};
        if(root->left)
            ans = dp(x, root->left, depth + 1, root->val);
        if(ans.first == -1 && root->right)
            ans = dp(x, root->right, depth + 1, root->val);
        
        return ans;
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL)
            return false;
        pair<int, int> ansX, ansY;
        ansX = dp(x, root, 0, -1);
        ansY = dp(y, root, 0, -1);
        if(ansX.first == ansY.first && ansX.second != ansY.second)
            return true;
        return false;
        
    }
};