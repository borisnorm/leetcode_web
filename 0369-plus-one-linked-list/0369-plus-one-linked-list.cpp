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
          return new ListNode(1);
        
        ListNode* rHead = reverseList(head);
        int carry = 1;
        int sum = 0;
        int digit = 0;

        ListNode* cur = rHead;
        while(cur)
        {
            sum = cur->val + carry;
            digit = sum % 10;
            carry = sum / 10;

            cur->val = digit;

            if (!cur->next && carry)
              cur->next = new ListNode(0);

            cur = cur->next;
        }

        return reverseList(rHead);
    }

    ListNode* reverseList(ListNode* head)
    {
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