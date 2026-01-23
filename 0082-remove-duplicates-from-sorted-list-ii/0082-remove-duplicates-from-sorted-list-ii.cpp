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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
          return head;

        ListNode dummy;
        ListNode* dummy_head = &dummy;
        dummy_head->next = head;

        ListNode* pre = dummy_head;
        ListNode* cur = head;
        ListNode* nxt = nullptr;

        while (cur && cur->next)
        {
           nxt = cur->next;
           if (cur->val == nxt->val)
           {
              int dupVal = cur->val;
              while (cur && cur->val == dupVal)
                cur = cur->next;
              
              pre->next = cur;
           }
           else
           {
              pre = cur;
              cur = cur->next;
           }
        }

        return dummy.next;
    }
};