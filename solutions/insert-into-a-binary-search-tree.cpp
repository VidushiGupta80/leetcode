//Insert into a Binary Search Tree -> 10/08/2020 10:09
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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // if(isLeaf(root))
        // {
        //     TreeNode* temp(val);
        //     if(val > root->val)
        //         root->right = temp;
        //     else
        //         root->left = temp;
        //     return root;
        // }
        if(!root)
        {
            TreeNode* temp = new TreeNode(val);
            return temp;
        }
        if(val > root->val)
        {
            if(root->right)
                insertIntoBST(root->right, val);
            else
            {
                TreeNode* temp = new TreeNode(val);
                root->right = temp;
            }
                
        }
        else if(val < root->val)
        {
            if(root->left)
                insertIntoBST(root->left, val);
            else
            {
                TreeNode* temp = new TreeNode(val);
                root->left = temp;
            }
                
        }
        return root;            
    }
};
