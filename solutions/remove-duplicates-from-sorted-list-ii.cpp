//Remove Duplicates from Sorted List II -> 05/31/2020 20:03
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        stack<ListNode*> stk;
        ListNode* trav = head;
        int cmp = INT_MAX;
        while(trav != NULL)
        {
            if(stk.empty() && trav->val != cmp)
                stk.push(trav);
            // else if(stk.empty() && trav->val == cmp)
            //     continue;
            else if(!stk.empty() && trav->val != stk.top()->val)
            {
                if(trav->val != cmp)
                    stk.push(trav);
            }
            
            else if(!stk.empty() && trav->val == stk.top()->val)
            {
                cmp = stk.top()->val;
                stk.pop();
            }  
            trav = trav->next;
        }
        ListNode* temp;
        if(stk.empty())
            return NULL;
        temp = stk.top();
        temp->next = NULL;
        
        while(!stk.empty())
        {
            temp = stk.top();
            stk.pop();
            if(!stk.empty())
                stk.top()->next = temp;
            else if(stk.empty())
                head = temp;
            
        }
        return head;
    }
};
