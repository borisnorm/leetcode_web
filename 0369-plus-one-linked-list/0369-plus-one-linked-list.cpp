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
    ListNode* plusOne(ListNode* head) {
        if (!head)
          return head;

        ListNode dummy(0);
        ListNode* dummy_head = &dummy;

        dummy_head->next = reverseList(head);

        int sum   = 0;
        int carry = 0;
        int digit = 0;
        ListNode* pre = dummy_head;
        ListNode* cur = pre->next;
        ListNode* nxt = nullptr;

        while(cur)
        {
           if (cur == dummy_head->next)
             sum = cur->val + 1 + carry;
           else
             sum = cur->val + carry;

           digit = sum % 10;
           carry = sum / 10;

           cur->val = digit;

           pre = cur;
           cur = cur->next;
        }

        if (carry)
          pre->next = new ListNode(carry);

        dummy_head->next = reverseList(dummy_head->next);

        return dummy.next;

    }

    ListNode* reverseList(ListNode* head)
    {
        if (!head)
          return nullptr;

        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* nxt = nullptr;

        while(cur)
        {
           nxt = cur->next;
           cur->next = pre;
           pre = cur;
           cur = nxt;
        }
        return pre;
    }
};