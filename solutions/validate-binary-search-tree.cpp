//Validate Binary Search Tree -> 06/07/2020 12:15
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
    bool check(TreeNode* root, long minimum, long maximum)
    {
        // if(isLeaf(root))
        //     return true;
        bool checkRoot = false;
        if(root->val > minimum && root->val < maximum)
            checkRoot = true;
        bool checkLeft = true;
        if(root->left)
            checkLeft = check(root->left, minimum, root->val);
        bool checkRight = true;
        if(root->right)
            checkRight = check(root->right, root->val, maximum);
        
        // if(checkLeft && checkRight)
        //     return true;
        // return false;
        return checkRoot && checkLeft && checkRight;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        bool checkLeft = true;
        bool checkRight = true;
        if(root->left)
            checkLeft = check(root->left, LONG_MIN, root->val);
        
        if(root->right)
            checkRight = check(root->right, root->val, LONG_MAX);
        return checkLeft && checkRight;
    }
};
