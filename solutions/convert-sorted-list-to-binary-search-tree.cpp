//Convert Sorted List to Binary Search Tree</a -> 05/31/2020 16:20
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
private:
    TreeNode* findRoot(vector<int>& arr, int start, int end)
    {
        if(start == end)
        {
            TreeNode* node;
            node = new TreeNode(arr[start]);
            return node;
        }
        else if(start > end)
            return NULL;
        
        int mid = (start + end) / 2;
        TreeNode* root;
        root = new TreeNode(arr[mid]);
        root->left = findRoot(arr, start, mid - 1);
        root->right = findRoot(arr, mid+1, end);
        
        return root;
        
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;
        ListNode* trav = head;
        while(trav)
        {
            arr.push_back(trav->val);
            trav = trav->next;            
        }
        int len = arr.size();
        int left = 0, right = len - 1;
        TreeNode* root;
        root = findRoot(arr, left, right);
        return root;
    }
};
