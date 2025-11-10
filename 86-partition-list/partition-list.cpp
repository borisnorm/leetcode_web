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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next)
          return head;

        ListNode dummy_less;
        ListNode dummy_greater;
        ListNode *less_tail = &dummy_less;
        ListNode *greater_tail = &dummy_greater;

        for (ListNode *p = head; p != nullptr; p = p->next)
        {
           if (p->val < x)
           {
              less_tail->next = p;
              less_tail = less_tail->next;
           }    
           else
           {
              greater_tail->next = p;
              greater_tail = greater_tail->next;
           }
        }

        less_tail->next = dummy_greater.next;
        greater_tail->next = nullptr;

        return dummy_less.next;
    }

};