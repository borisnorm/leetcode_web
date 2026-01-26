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
        
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode dummy(0);
        ListNode* cur = &dummy;

        int carry = 0;
        int sum = 0;

        while(l1 || l2 || carry)
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
           carry = sum/10;
           sum = sum%10;
           
           cur->next = new ListNode(sum);
           cur = cur->next;
        }

        dummy.next = reverseList(dummy.next);

        return dummy.next;
    }

    ListNode* reverseList(ListNode* head)
    {
        if (!head || !head->next)
          return head;

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