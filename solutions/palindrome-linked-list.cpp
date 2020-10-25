//Palindrome Linked List -> 05/31/2020 17:46
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
    bool isPalindrome(ListNode* head) {
         
        int size = 0;
        ListNode* tail = get_size_and_tail(head, size);
        ListNode* mid = get_mid(head, size);
        reverse(mid);
        const bool palindrome = compare_values(head, tail, size / 2);
        reverse(tail);
        return palindrome;
    }

    ListNode* get_size_and_tail(ListNode* p, int& size)
    {
        ListNode* tail = 0;
        while (p)
        {
            ++size;
            tail = p;
            p = p->next;
        }
        return tail;
    }

    ListNode* get_mid(ListNode* head, int size)
    {
        ListNode* p = head;
        for (int i = 0; i < size / 2; ++i, p = p->next);
        return p;
    }

    void reverse(ListNode* head)
    {
        ListNode* prev = 0;
        ListNode* p = head;
        for (int i = 0; p; ++i)
        {
            ListNode* next = p->next;

            if (prev != 0)
                p->next = prev;

            prev = p;
            p = next;
        }
        if (prev)
        {
            head->next = nullptr;
        }
    }

    bool compare_values(ListNode* h1, ListNode* h2, int count)
    {
        int i = 0;
        for (auto p1 = h1, p2 = h2; i < count && p1 && p2; ++i, p1 = p1->next, p2 = p2->next)
        {
            if (p1->val != p2->val)
            {
                return false;
            }
        }
        return true;
    }
};
