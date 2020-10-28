//Vertical Order Traversal of a Binary Tree</a -> 08/07/2020 22:51
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
bool sortCol(pair<int, int> arr1, pair<int, int> arr2)
     {
         return arr1.second == arr2.second ? arr1.first < arr2.first : arr1.second < arr2.second;
     }

class Solution {
    void dfs(int level, TreeNode* root,  map<int, vector<pair<int, int> > >& node)
    {
        queue<pair<TreeNode*, pair<int, int> > >bfs;
        bfs.push(make_pair(root, make_pair(level, 0)));
        while(!bfs.empty())
        {
            int level = bfs.front().second.first;
            int levelOrder = bfs.front().second.second;
            TreeNode* trav = bfs.front().first;
            node[level].push_back(make_pair(trav->val, levelOrder));
            if(trav->left)
                bfs.push(make_pair(trav->left, make_pair(level - 1, levelOrder + 1)));
            if(trav->right)
                bfs.push(make_pair(trav->right, make_pair(level + 1, levelOrder + 1)));
            bfs.pop();
        }
        return;
      
    }

    
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int> > >node;
        dfs(0, root, node);
        vector<vector<int> > ans;
        map<int, vector<pair<int, int> > > :: iterator it;
        for(it = node.begin(); it != node.end(); it++)
        {
            sort(it->second.begin(), it->second.end(), sortCol);
            vector<int> temp;
            for(int i = 0; i < it->second.size(); i++)
            {
                temp.push_back(it->second[i].first);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
