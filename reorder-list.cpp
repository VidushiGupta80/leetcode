//Reorder List -> 08/21/2020 12:02
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
    void reorderList(ListNode* head) {
          ListNode* h = head;
        deque<ListNode*> ll;
        while(h!=NULL){
            ll.push_back(h);
            h=h->next;
        }         
        
        if(ll.size()<=1)
            return;
        
        ListNode* t=NULL;
        while(!ll.empty()){
            if(ll.size()>=2){
                if(t!=NULL)
                    t->next=ll.front(); 
            
                ll.front()->next=ll.back();
                t=ll.back();
                ll.pop_front();
                ll.pop_back();            
            } else{     
                t->next=ll.front();
                t=t->next;                        
                ll.pop_front();            
            }
        }
        t->next=NULL;
    }
};
