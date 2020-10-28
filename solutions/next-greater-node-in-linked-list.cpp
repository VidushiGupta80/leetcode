//Next Greater Node In Linked List -> 05/30/2020 18:44

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> answer(10001, 0);
        stack<pair<int, int> > stk;
        int index = 0;
        ListNode* trav = head;
        int count = 0;
        while(trav != NULL)
        {
            while(!stk.empty() && trav->val > stk.top().first)
            {
              answer[stk.top().second] = trav->val;
              stk.pop();
            }
            stk.push(make_pair(trav->val, index));
            index++;
            trav = trav->next;
            count++;
        }
        // while(!stk.empty())
        // {
        //     answer[stk.top().second] = 0;
        //     stk.pop();
        // }
        answer.resize(count);
        return answer;
    }
};