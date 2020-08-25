//Binary Tree Level Order Traversal -> 08/25/2020 10:51
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        vector<int> currLevel;
        if(root == NULL)
            return ans;
        queue<pair<TreeNode*, int> > bfs;
        bfs.push(make_pair(root, 0));
        int curr = 0;
        while(!bfs.empty())
        {
            int value = bfs.front().first->val;
            int level = bfs.front().second;
            if(curr == level)
                currLevel.push_back(value);
            else if(curr != level)
            {
                ans.push_back(currLevel);
                currLevel.clear();
                curr = level;
                currLevel.push_back(value);
            }
            TreeNode* node = bfs.front().first;
            if(node->left)
                bfs.push(make_pair(node->left, level + 1));
            if(node->right)
                bfs.push(make_pair(node->right, level + 1));
            bfs.pop();
        }
        ans.push_back(currLevel);
        return ans;
    }
};
