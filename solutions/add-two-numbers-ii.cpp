//Add Two Numbers II -> 05/30/2020 17:47
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         long long num1 = 0, num2 = 0, num;
//         int count1 = 0, count2 = 0, count;
//         ListNode* trav1 = l1;
//         while(trav1 != NULL)
//         {
//             num1 = num1 * 10 + trav1->val;
//             count1++;
//             trav1 = trav1->next;
//         }
//         ListNode* trav2 = l2;
//         while(trav2 != NULL)
//         {
//             num2 = num2 * 10 + trav2->val;
//             count2++;
//             trav2 = trav2 ->next;
//         }
//         num = num1 + num2;
//         count = max(count1, count2);
//         int digit = num / (pow(10, count));
//         if(digit == 0)
//         {
//             count--;
//         }
//         digit = num / (pow(10, count));
//         ListNode* head = new ListNode (digit);
       
//         // head->val = digit;
//         // head->next = NULL;
//         ListNode* trav = head;
//         num = num % (long long)powl(10, count);
//         count--;
//         while(count >= 0)
//         {
//             digit = num / (pow(10, count));
//             ListNode* temp = new ListNode (digit);
            
//             // temp->val = digit;
//             // temp->next = NULL;
//             trav ->next = temp;
//             trav = temp;
//             num = num % (long long)powl(10, count);
//             count--;
//         }
//         return head;
        
        
        
        if(!l1 && !l2)
            return nullptr;
        
        string n1,n2;
        while(l1)
        {
            n1+=(l1->val + '0');
            l1 = l1->next;
        }
        while(l2)
        {
            n2+=(l2->val + '0');
            l2 = l2->next;
        }
        
        //int n = std::max(n1.length(),n2.length());
        int i = n1.length()-1;
        int j = n2.length()-1;
        int rem = 0;
        
        string s="";
        while(i>=0 || j>=0)
        {
            char val1 = i<0? '0':n1[i];
            char val2 = j<0? '0':n2[j];
            int sum = (val1-'0')+(val2-'0')+rem;
            rem = sum>9 ? 1:0;
            sum = sum>9 ? (sum%10) : sum;
            s.insert(s.begin(),(sum+'0'));                          
            i--;j--;
        }
        if(rem==1)
           s.insert(s.begin(),(rem+'0'));
        
        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        for(size_t i=0;i<s.length();i++)
        {
            int val = (s[i]-'0');
            if(!head)
            {
                head = new ListNode(val);
                prev = head;
            }
            else
            {
                prev->next = new ListNode(val);
                prev = prev->next;
            }
                         
        }
        
        return head;
    }
        
};
