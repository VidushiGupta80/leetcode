//Check Completeness of a Binary Tree -> 06/06/2020 18:57

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
public:
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL)
            return false;
        else if(isLeaf(root))
            return true;
        bool miss = false;
        bool missLeft = false, missRight = false;
        queue<TreeNode*> levelOrder;
        levelOrder.push(root);
        while(!levelOrder.empty())
        {
            if(!miss)
            {
                if(levelOrder.front()->left)
                    levelOrder.push(levelOrder.front()->left);
                else if(!levelOrder.front()->left)
                {
                    miss = true;
                    missLeft = true;
                }
                if(levelOrder.front()->right)
                    levelOrder.push(levelOrder.front()->right);
                else if(!levelOrder.front()->right)
                {
                    miss = true;
                    missRight = true;
                }
                levelOrder.pop();
            }
            else if(miss)
            {
                if(missLeft && !missRight)
                    return false;
                else if((!missLeft && missRight) || (missLeft && missRight))
                {
                    if(isLeaf(levelOrder.front()))
                        levelOrder.pop();
                    else if(!isLeaf(levelOrder.front()))
                        return false;
                }
            }
        }
        
            return true;
    }
};