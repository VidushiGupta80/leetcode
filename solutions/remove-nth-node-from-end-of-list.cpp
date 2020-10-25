//Remove Nth Node From End of List</a -> 05/28/2020 13:14
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* trav1 = head;
        ListNode* trav2 = head;
        if(head == NULL)
            return NULL;
        else if(head->next == NULL)
            return NULL;
        while(n > 0 && trav2 != NULL)
        {
            trav2 = trav2 -> next;
            n--;
        }
        if(trav2 == NULL)
        {
            trav1 = trav1 -> next;
            return trav1;
        }
        else
        {
            while(trav2->next != NULL)
            {
                trav1= trav1-> next;
                trav2 = trav2->next;
            }
            trav1->next = trav1->next->next;
            return head;
        }
    }
};
