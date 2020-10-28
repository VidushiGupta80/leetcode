//Maximum Level Sum of a Binary Tree</a -> 06/16/2020 18:37

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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int> > levelOrder;
        int level = 1;
        TreeNode* trav = root;
        levelOrder.push(make_pair(root, level));
        map<int, int> record;
        while(!levelOrder.empty())
        {
            trav = levelOrder.front().first;
            int temp = levelOrder.front().second;
            if(record.find(temp) != record.end())
                record[temp] += trav->val;
            else
                record[temp] = trav->val;
            if(trav->left)
                levelOrder.push(make_pair(trav->left,temp + 1 ));
            if(trav->right)
                levelOrder.push(make_pair(trav->right, temp + 1));
            levelOrder.pop();
        }
        map<int, int> rev;
        map<int, int> :: iterator it = record.begin();
        for(; it != record.end(); it++)
        {
            rev[it->second] = it->first;
        }
        map<int, int> :: reverse_iterator itr = rev.rbegin();
        return itr->second;
    }
};