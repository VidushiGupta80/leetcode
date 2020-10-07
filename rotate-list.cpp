//Rotate List -> 10/07/2020 15:55
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0)
            return head;
        int length = 0;
        ListNode* trav = head;
        ListNode* headNew = head;
        while(trav != NULL)
        {
            length++;
            trav = trav->next;
        }
        k = k % length;
        if(k == 0)
            return head;
        for(int i = 0; i < length - k; i++)
        {
            headNew = headNew->next;
        }
        trav = headNew;
        while(trav->next != NULL)
            trav = trav->next;
        trav->next = head;
        while(trav->next != headNew)
            trav = trav->next;
        trav->next = NULL;
        return headNew;
    }
};
