//All Possible Full Binary Trees -> 08/19/2020 20:00
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
vector<TreeNode*> construct(int N, map<int, vector<TreeNode*> >& cache)
{
    if(cache.find(N) != cache.end())
        return cache[N];
    vector<TreeNode*> curr;
    for(int i = 1; i <= N - 2; i += 2)
    {
        vector<TreeNode*> leftSub = construct(i, cache);
        vector<TreeNode*> rightSub = construct(N - i -1, cache);
        for(int l = 0; l < leftSub.size(); l++)
        {
            for(int r = 0; r < rightSub.size(); r++)
            {
                TreeNode* temp = new TreeNode();
                temp->left = leftSub[l];
                temp->right = rightSub[r];
                curr.push_back(temp);
            }
        }
    }
    return cache[N]  = curr;
}
  
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> ans;
        map<int, vector<TreeNode*> > cache;
        cache[1].push_back(new TreeNode());
        if(N == 1)
            return cache[N];
        if(N % 2 == 0)
            return ans;
        return construct(N, cache);
    }
};
