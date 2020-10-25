//Symmetric Tree -> 08/29/2020 20:26
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
bool isSymm(vector<int> arr)
{
    for(int i = 0, j = arr.size() - 1; i <= j; i++, j--)
    {
        if(arr[i] != arr[j])
            return false;
    }
    return true;
}
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        queue<pair<TreeNode*, int> > bfs;
        bfs.push(make_pair(root, 0));
        vector<int> comp;
        int currLevel = 0;
        while(!bfs.empty())
        {
            int level = bfs.front().second;
            
            TreeNode* temp = bfs.front().first;
            int value = temp->val;
            if(currLevel == level)
            {
                comp.push_back(value);
            }
            else if(currLevel != level)
            {
                bool ans = isSymm(comp);
                if(ans)
                    comp.clear();
                else
                    return false;
                comp.push_back(value);
                currLevel = level;
            }
            TreeNode* rand = new TreeNode(INT_MIN);
            if(temp->val != INT_MIN && temp->left)
                bfs.push(make_pair(temp->left, level + 1));
            else if(temp->val != INT_MIN && !temp->left)
                          
                bfs.push(make_pair(rand, level + 1));
            if(temp->val != INT_MIN && temp->right)
                bfs.push(make_pair(temp->right, level + 1));
            else if(temp->val != INT_MIN && !temp->right)
                bfs.push(make_pair(rand, level + 1));
            bfs.pop();
            
        }
        return true;
    }
};
