//Maximum Binary Tree -> 08/19/2020 15:18
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
 int findIndex(int s, int e, vector<int>& nums)
 {
     int maxIndex = s;
     for(int i = s; i <= e; i++)
     {
         if(nums[i] > nums[maxIndex])
             maxIndex = i;
     }
     return maxIndex;
 }
    
TreeNode* construct(int s, int e, vector<int>& nums)
{
    if(s == e)
    {
        TreeNode* temp = new TreeNode(nums[s]);
        return temp;
    }
    if(s > e)
        return NULL;
    int i = findIndex(s, e, nums);
    TreeNode* temp = new TreeNode(nums[i]);
    temp->left = construct(s, i - 1, nums);
    temp->right = construct(i + 1, e, nums);
    return temp;
}
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = construct(0, nums.size() - 1, nums);
        return root;
    }
};
