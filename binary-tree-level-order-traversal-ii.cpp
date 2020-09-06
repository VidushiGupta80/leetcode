//Binary Tree Level Order Traversal II -> 09/06/2020 17:29
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<pair<TreeNode*, int> > bfs;
        vector<vector<int> > ans;
        if(!root)
            return ans;
        vector<int> curr;
        int level = 0;
        bfs.push(make_pair(root, 0));
        while(!bfs.empty())
        {
            int currLevel = bfs.front().second;
            TreeNode* currNode = bfs.front().first;
            if(currLevel == level)
                curr.push_back(currNode->val);
            else if(currLevel != level)
            {
                ans.insert(ans.begin(), curr);
                curr.clear();
                curr.push_back(currNode->val);
                level = currLevel;
            }
            if(currNode->left)
                bfs.push(make_pair(currNode->left, currLevel + 1));
            if(currNode->right)
                bfs.push(make_pair(currNode->right, currLevel + 1));
            bfs.pop();
            
        }
        ans.insert(ans.begin(), curr);
        return ans;
    }
};
