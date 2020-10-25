//Intersection of Two Linked Lists -> 09/05/2020 15:06
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         ListNode* A=headA;
        ListNode*B=headB;
        int Asize=0,Bsize=0,diff;
        while(A!=NULL)
        {
            Asize++;
            A=A->next;
        }
        while(B!=NULL)
        {
            Bsize++;
            B=B->next;
        }
        diff=abs(Asize-Bsize);
        if(Asize>=Bsize)
        {
            while(diff--)
                headA=headA->next;
        }
        else
        {
            while(diff--)
                headB=headB->next;
        }
        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};
