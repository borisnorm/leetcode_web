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
        if (!l1 && !l2)
          return nullptr;
        if (!l1)
          return l2;
        if (!l2)
          return l1;

        int carry = 0;
        int sum = 0;
        
        ListNode* head = nullptr;
        ListNode* prev = nullptr;

        while (l1 || l2 || carry)
        {
           int l1_val = 0;
           int l2_val = 0;

           if (l1)
           {
             l1_val = l1->val;
             l1 = l1->next;
           }
           if (l2)
           {
             l2_val = l2->val;
             l2 = l2->next;
           }
           sum = l1_val + l2_val + carry;

           carry = sum / 10;
           sum   = sum % 10;

           ListNode* cur = new ListNode(sum);
           if (!head)
             head = cur;
           if (prev)
             prev->next = cur;
           prev = cur;
        }

        return head;
    }
};