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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
          return head;

        int cnt = 0;
        ListNode* tail = head;
        while (tail)
        {
          cnt++;
          tail = tail->next;
        }

        if (cnt < n)
          return nullptr;
        // n = 1, idx = cnt - 1;
        // n = 2  idx = cnt - 2;
        // n = 3, idx = cnt - 3

        int idx = 0;
        ListNode dummy(0);
        ListNode* dummy_head = &dummy;
        dummy_head->next = head;

        ListNode* cur = head;
        ListNode* pre = dummy_head;
        while (cur)
        {
          if (idx == cnt - n)   // cnt >= n
          {
             pre->next = cur->next;
             break;
          }
           
          idx++;
          pre = cur;
          cur = cur->next;
        }

       return dummy_head->next;
    }
};