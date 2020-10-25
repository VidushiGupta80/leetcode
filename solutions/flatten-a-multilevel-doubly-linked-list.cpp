//Flatten a Multilevel Doubly Linked List -> 05/31/2020 11:18
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
// private:
//     Node* findLast(Node* head)
//     {
//         if(head == NULL)
//             return NULL;
        
//         Node* trav = head;
//         Node* tail = trav->prev;
//         while(true)
//         {
//             if(trav!= NULL && trav->child == NULL)
//             {
//                 tail = trav;
//                 trav = trav->next;
//             }
//             else if(trav != NULL && trav->child != NULL)
//             {
//                 Node* last;
//                 last = findLast(trav->child);
//                 if(trav->next)
//                     last->next = trav->next;
//                 last->next->prev = last;
//                 trav->next = trav->child;
//                 trav->child->prev = trav;
//                 trav->child = NULL;
//                 trav = last->next;
//                 if(trav)
//                     tail = trav->prev;
//             }
//             else if(trav == NULL)
//             {
//                 break;
//             }
//         }
//         return tail;
//     }
public:
    Node* flatten(Node* head) {
//         Node* temp = findLast(head);
        
//         return head;
        
        
        
         if(!head) return nullptr;
      Node *p=head;
      while(p)
      {
          if(!p->child) p=p->next;
          else
          {
              Node *temp=p->next;
              p->next=flatten(p->child);
              p->next->prev=p;
              Node *track=p->next;
              while(track->next) track=track->next;
              track->next=temp;
              if(temp) temp->prev=track;
              p->child=nullptr;
              p=temp;
          }
        }
        return head;
    }
};
