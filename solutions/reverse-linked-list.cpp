//Reverse Linked List -> 10/01/2020 14:09
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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* fwd = curr->next;
        while(curr != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = fwd;
            if(curr->next)
                fwd = curr->next;
            else break;
        }
        curr->next = prev;
        return curr;
    }
};
