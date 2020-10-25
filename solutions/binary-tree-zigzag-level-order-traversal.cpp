//Binary Tree Zigzag Level Order Traversal -> 09/04/2020 12:25
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<pair<TreeNode*, int> > bfs;
        vector<vector<int> > ans;
        if(!root)
            return ans;
        vector<int> temp;
        bfs.push(make_pair(root, 0));
        int level = 0;
        while(!bfs.empty())
         {
             TreeNode* currNode = bfs.front().first;
             int currLevel = bfs.front().second;
             if(level == currLevel)
             {
                 temp.push_back(currNode->val);
             }
             else if(level != currLevel)
             {
                 if(level % 2 == 0)
                     ans.push_back(temp);
                 else if(level % 2 == 1)
                 {
                     reverse(temp.begin(), temp.end());
                     ans.push_back(temp);
                 }
                 temp.clear();
                 temp.push_back(currNode->val);
                 level = currLevel;
             }
             if(currNode->left)
                 bfs.push(make_pair(currNode->left, level + 1));
             if(currNode->right)
                 bfs.push(make_pair(currNode->right, level + 1));
             bfs.pop();
         }
         if(level % 2 == 0)
            ans.push_back(temp);
         else if(level % 2 == 1)
         {
             reverse(temp.begin(), temp.end());
             ans.push_back(temp);
         }
        return ans;
    }
};
