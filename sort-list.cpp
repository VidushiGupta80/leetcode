//Sort List -> 08/25/2020 17:09
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
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* head;
        ListNode* trav1;
        ListNode* trav2;
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        if(l1->val <= l2->val)
            head = l1;
        else
            head = l2;
        trav1 = l1;
        trav2 = l2;
        ListNode* temp;
        while(trav1->next != NULL && trav2->next != NULL)
        {
            if(trav1->val <= trav2->val)
            {
                if(trav1->next->val > trav2->val)
                {
                   temp = trav1;     
                    trav1 = trav1->next;
                    temp->next = trav2;
                }
                else if(trav1->next->val <= trav2->val)
                   trav1 = trav1->next;
                
            }
            else if(trav1->val > trav2->val)
            {
                if(trav2->next->val >= trav1->val)
                {
                    temp = trav2; 
                    trav2 = trav2->next;
                    temp->next = trav1;
                }
                else
                    trav2 = trav2->next;                
            }     
            
        }
        if(trav1->next == NULL && trav2->next != NULL)
        {
            while(trav2->next != NULL)
            {
                if(trav1->val <= trav2->val)
                {
                    trav1->next = trav2;
                    break;
                }
                else if(trav2->next->val >= trav1->val)
                {
                    temp = trav2;
                    trav2 = trav2->next;
                    temp->next = trav1;
                }
                else
                    trav2 = trav2->next;
            }  
        }
        else if(trav1->next != NULL && trav2->next == NULL)
        {
           while(trav1->next != NULL)
            {
               if(trav2->val < trav1->val)
                {
                    trav2->next = trav1;
                    break;
                } 
               else if(trav2->val >= trav1->val)
               {
                   if(trav1->next->val > trav2->val)
                    {
                        temp = trav1;
                        trav1 = trav1->next;
                        temp->next = trav2;
                    }
                    else
                        trav1 = trav1->next;
               }
               
            }  
        }
        if(trav1->next == NULL && trav2->next == NULL)
        {
            if(trav1->val <= trav2->val)
                trav1->next = trav2;
            else
                trav2->next = trav1;
        }
        return head;
    }
    
ListNode* mergeSort(ListNode* head)
{
    if(head == NULL)
        return head;
    if(head->next == NULL)
        return head;
    ListNode* l1;
    ListNode* l2;
    ListNode* s;
    ListNode* f;
    s = head;
    f = head->next;
    while(f && f->next)
    {
        if(s->next)
            s = s->next;
        if(f->next->next)
            f = f->next->next;
        else break;
    }
    l2 = s->next;
    s->next = NULL;
    l1 = mergeSort(head);
    l2 = mergeSort(l2);
    
    return mergeTwoLists(l1, l2);
}
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
