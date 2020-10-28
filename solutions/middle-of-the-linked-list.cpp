//Middle of the Linked List -> 05/29/2020 22:59

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
    ListNode* middleNode(ListNode* head) {
        ListNode* trav1 = head;
        ListNode* trav2 = head;
        while(trav2 != NULL && trav2->next != NULL)
        {
            trav1 = trav1->next;
            trav2 = trav2->next->next;
        }
        return trav1;
    }
};