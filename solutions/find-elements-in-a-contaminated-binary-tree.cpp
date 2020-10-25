//Find Elements in a Contaminated Binary Tree</a -> 06/07/2020 13:03
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
class FindElements {
public:
    set<int> myset;
    bool isLeaf(TreeNode* root)
    {
        if(root->left == NULL && root->right == NULL)
            return true;
        return false;
    }
    void helper(TreeNode* root)
    {
        if(isLeaf(root))
            return;
        int x = root->val;
        if(root->left)
        {
            root->left->val = 2 * x + 1;
            myset.insert(root->left->val);
        }
        if(root->right)
        {
            root->right->val = 2 * x + 2;
            myset.insert(root->right->val);
        }
        if(root->left)
            helper(root->left);
        if(root->right)
            helper(root->right);
    }
    FindElements(TreeNode* root) {
        if(root ==  NULL)
            return;
        root->val = 0;
        myset.insert(0);
        helper(root);
        return;
    }
    
    bool find(int target) {
        if(myset.find(target) != myset.end())
            return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
