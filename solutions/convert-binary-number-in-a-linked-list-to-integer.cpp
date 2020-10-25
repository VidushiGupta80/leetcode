//Convert Binary Number in a -> 06/18/2020 17:03
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
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        ListNode* trav = head;
        int ans = trav->val;
        // if(trav->next)
            trav = trav->next;
        while(trav!= NULL)
        {
            ans = 2 * ans + trav->val;
            trav = trav->next;
        }
        return ans;
    }
};
