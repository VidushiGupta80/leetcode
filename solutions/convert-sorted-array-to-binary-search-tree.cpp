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
TreeNode* createTree(int left, int right, vector<int>& nums)
{
    if(left == right)
    {
        TreeNode* node = new TreeNode(nums[left]);
        return node;
    }
    if(left > right)
        return NULL;
    int mid = (left + right) / 2;
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = createTree(left, mid - 1, nums);
    node->right = createTree(mid + 1, right, nums);
    return node;
}
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createTree(0, nums.size() - 1, nums);
    }
};