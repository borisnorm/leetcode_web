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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
          return nullptr;
        
        ListNode  dummy;
        ListNode* dummy_head = &dummy;
        dummy_head->next = head;

        ListNode* pre = dummy_head;
        ListNode* cur = dummy_head->next;
        ListNode* nxt = nullptr;

        while(cur)
        {
           if (cur->val == val)
           {
              nxt = cur->next;
              
              pre->next = nxt;
              delete cur;

              cur = nxt;
           }
           else
           {
             pre = cur;
             cur = cur->next;
           }
        }

        return dummy_head->next;
    }
};