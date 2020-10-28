//Minimum Distance Between BST Nodes -> 06/06/2020 19:11

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
private:
    bool isLeaf(TreeNode* root)
    {
        if(root->left == NULL && root->right == NULL)
            return true;
        return false;
    }
    
    void inOrder(TreeNode* root, vector<int>& ans)
    {
        if(isLeaf(root))
        {
            ans.push_back(root->val);
            return;
        }
        
        if(root->left)
            inOrder(root->left, ans);
        ans.push_back(root->val);
        if(root->right)
            inOrder(root->right, ans);
        
        return;
    }
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> ans;
        inOrder(root, ans);
        int minimum = INT_MAX;
        int len = ans.size();
        for(int i = 0, j = i + 1; j < len; i++, j++)
        {
            minimum = min(minimum, abs(ans[i] - ans[j]));
        }
        return minimum;
    }
};