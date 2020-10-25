//Merge Two Binary Trees -> 08/20/2020 16:24
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
 TreeNode* fun(TreeNode *a,TreeNode *b){
        
        if(a==NULL&&b==NULL)
            return NULL;
        
        if(a==NULL&&b!=NULL)
            return b;
        
        if(b==NULL&&a!=NULL)
            return a;
        
        TreeNode *x = new TreeNode(a->val+b->val);
        x->left =  fun(a->left,b->left);
        x->right = fun(a->right,b->right);
        
        return x;
 }
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return fun(t1, t2);        
        
    }
};
