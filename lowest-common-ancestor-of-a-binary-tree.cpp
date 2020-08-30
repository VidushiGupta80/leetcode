//Lowest Common Ancestor of a Binary Tree</a -> 08/30/2020 14:10
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
bool finder(TreeNode* root, TreeNode* temp, stack<TreeNode*>& stk)
{
    if(root->val == temp->val)
    {
        stk.push(temp);
        return true;
    }
    bool ans = false;
    if(root->left)
        ans = ans || finder(root->left, temp, stk);
    if(!ans && root->right)
        ans = ans || finder(root->right, temp, stk);
    if(ans)
        stk.push(root);
    return ans;
}
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        finder(root, p, stk1);
        finder(root, q, stk2);
        TreeNode* ans = root;
        while(!stk1.empty() && !stk2.empty())
        {
            if(stk1.top()->val == stk2.top()->val)
            {
                ans = stk1.top();
                stk1.pop();
                stk2.pop();
            }
            else break;
        }
        return ans;
    }
};
