//Kth Smallest Element in a BST -> 06/03/2020 22:03
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
    
    void inOrder(vector<int>& ans, TreeNode* root)
    {
        if(isLeaf(root))
        {
            ans.push_back(root->val);
            return;
        }
        
        
        
        if(root->left)
            inOrder(ans, root->left);
        ans.push_back(root->val);
        if(root->right)
            inOrder(ans, root->right);
        
        return;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inOrder(ans, root);
        return ans[k - 1];
    }
};
