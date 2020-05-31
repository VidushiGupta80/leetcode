//Reverse Nodes in k-Group -> 05/31/2020 17:41
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
    
     ListNode *prev=NULL;
            int cot=0;
            ListNode *vhead;
ListNode *reverse(ListNode *st,int k)
{
    cot++;
    
    ListNode *a=st,*b=st->next,*c=st,*copy=st;
    int ct=0,len=0;
    while(copy!=NULL)
    {
        copy=copy->next;
        len++;
        if(len==k)
            break;
    }
    // cout<<len<<"length\n";
    if(len<k)
    {
        prev->next=st;
        return NULL;
    }
    a->next=NULL;
    while(ct<k-1 && b!=NULL)
    {
       
        c=b->next;
        b->next=a;
        a=b;
        b=c;
        ct++;
    }
    if(cot!=1)
    {
    prev->next=a;
    prev=st;
    }
    else
        vhead=a;
    return b;
}
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        prev=head;
        while(head!=NULL)
        {
            head=reverse(head,k);
            if(head==NULL)
                break;
        }
        return vhead;
    
    
    
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode* trav = head;
//         if(head == NULL)
//             return NULL;
//         stack<ListNode*> stk;
//         int count = 0;
//         ListNode* travHead = NULL;
//         ListNode* trav1 = head;
//         ListNode* head1 = trav1;
//         while(trav1 != NULL && count < k)
//         {
//             head1 = trav1;
//             trav1 = trav1->next;
//             count++;
//         }
//         if(trav1 == NULL && count < k)
//             return head;
//         while(trav!= NULL)
//         {
            
//             while(trav!= NULL && count < k)
//             {
//                 stk.push(trav);
//                 trav = trav->next;
//                 count++;
//             }
//             if(trav == NULL && count < k)
//             {
//                 ListNode* temp;
//                 while(!stk.empty())
//                 {
//                     temp = stk.top();
//                     stk.pop();
//                 }
//                 if(travHead)
//                     travHead ->next = temp;
//             }
//             else if((trav != NULL && count == k) || (trav == NULL && count == k))
//             {
//                 if(travHead)
//                         travHead -> next = stk.top();
//                 while(!stk.empty())
//                 {
                    
//                     ListNode* temp = stk.top();
                    
//                     stk.pop();
//                     if(!stk.empty())
//                        temp->next = stk.top();
//                     else if(trav != NULL && stk.empty())
//                         travHead = temp;
//                     else if(trav == NULL && stk.empty())
//                         temp->next == NULL;
//                 }
//             }
//             if(trav == NULL)
//                 break;
//             count = 0;
//         }
//         return head1;
    }
};
