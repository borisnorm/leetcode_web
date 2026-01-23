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
        
        ListNode* cur = head;

        while(cur && cur->next)
        {
           if (cur->val == cur->next->val)
           {
               ListNode* nxt = cur->next;
               cur->next = nxt->next;
           }
           else
           {
              cur = cur->next;
           }
        }

        return head;
    }
/*
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
          return head;

        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* nxt = nullptr;
        while (cur)
        {
           if (cur->val == pre->val)
           {
              nxt = cur->next;
              pre->next = nxt;

              delete cur; 
              cur = pre;   
           }

           pre = cur;
           cur = cur->next;
        }

        return head;
    }
*/
};