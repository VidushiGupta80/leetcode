//Construct Binary Search Tree from Preorder Traversal -> 08/19/2020 14:03

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
TreeNode* finder(int s, int e, vector<int>& preorder)
{
    if(s == e)
    {
        TreeNode* temp = new TreeNode(preorder[s]);
        return temp;
    }
    if(s > e)
        return NULL;
    
    TreeNode* temp = new TreeNode(preorder[s]);
    int i = s;
    for(i = s; i <= e ; i++)
    {
        if(preorder[i] > preorder[s])
            break;
    }
    temp->left = finder(s + 1, i - 1, preorder);
    temp->right = finder(i, e, preorder);
    return temp;
}
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = finder(0, preorder.size() - 1, preorder);
        
        return root;
    }
};