//Binary Tree Inorder Traversal -> 06/04/2020 18:24
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
    
    void InOrder(vector<int>& ans, TreeNode* root)
    {
        if(isLeaf(root))
        {
            ans.push_back(root->val);
            return;
        }
        
        if(root->left)
            InOrder(ans, root->left);
        ans.push_back(root->val);
        if(root->right)
            InOrder(ans, root->right);
        
        return;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        InOrder(ans, root);
        return ans;
    }
};
