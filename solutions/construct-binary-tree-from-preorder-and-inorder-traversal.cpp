//Construct Binary Tree from Preorder and Inorder -> 08/29/2020 15:16
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
int finder(int num, int s, int e, vector<int>& inorder)
{
    int i;
    for(i = s; i <= e; i++)
    {
        if(inorder[i] == num)
            break;
    }
    return i;
}
TreeNode* builder(int sp, int ep, int si, int ei, vector<int>& preorder, vector<int>& inorder)
{
    if(sp > ep)
        return NULL;
    TreeNode* root = new TreeNode(preorder[sp]);
    if(sp == ep)
    {
        return root;
    }
    int index = finder(preorder[sp], si, ei, inorder);
    int diff = index - si;
    root->left = builder(sp + 1, sp + diff, si, index - 1, preorder, inorder);
    root->right = builder(sp + diff + 1, ep, index + 1, ei, preorder, inorder);
    return root;
}
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return builder(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
    }
};
