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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue<pair<int, TreeNode*> > bfs;
        bfs.push({1, root});
        int level = 1;
        while(true)
        {
            level = bfs.front().first;
            TreeNode* node = bfs.front().second;
            bfs.pop();
            if(node->left == NULL && node->right == NULL)
                break;
            if(node->left)
                bfs.push({level + 1, node->left});
            if(node->right)
                bfs.push({level + 1, node->right});
            
        }
        return level;
    }
};