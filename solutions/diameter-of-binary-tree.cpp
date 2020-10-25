//Diameter of Binary Tree -> 10/13/2020 23:31
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
bool isLeaf(TreeNode* root)
{
    if(root->left == NULL && root->right == NULL)
        return true;
    return false;
}
pair<int, int> traverse(TreeNode* root)
{
    if(isLeaf(root))
        return {0, 0};
    pair<int, int> leftSubTree = {0,-1};
    pair<int, int> rightSubTree = {0,-1};
    if(root->left)
        leftSubTree = traverse(root->left);
    if(root->right)
        rightSubTree = traverse(root->right);
    int diameter = 0;
    int len = 0;
    diameter = max(leftSubTree.first, rightSubTree.first);
    if(leftSubTree.second != -1)
        len = leftSubTree.second + 1;
    if(rightSubTree.second != -1)
        len += rightSubTree.second + 1;
    
    // len = leftSubTree.second + rightSubTree.second + 2;
    return {max(diameter, len), max(leftSubTree.second, rightSubTree.second) + 1};
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        return traverse(root).first;
    }
};
