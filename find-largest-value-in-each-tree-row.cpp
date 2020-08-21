//Find Largest Value in Each Tree Row</a -> 08/21/2020 19:17
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
    vector<int> largestValues(TreeNode* root) {
        queue<pair<TreeNode*,int> > bfs;
        bfs.push(make_pair(root, 0));
        int maxValue = INT_MIN;
        int onGoingLevel = 0;
        vector<int> ans;
        if(root == NULL)
            return ans;
        while(!bfs.empty())
        {
            int currVal = bfs.front().first->val;
            int currLevel = bfs.front().second;
            TreeNode* temp = bfs.front().first;
            if(onGoingLevel == currLevel)
                maxValue = max(maxValue, currVal);
            else if(onGoingLevel != currLevel)
            {
                onGoingLevel = currLevel;
                ans.push_back(maxValue);
                maxValue = currVal;
            }
            if(temp->left)
                bfs.push(make_pair(temp->left, currLevel + 1));
            if(temp->right)
                bfs.push(make_pair(temp->right, currLevel + 1));
            bfs.pop();
        }
        ans.push_back(maxValue);
        return ans;
    }
};
