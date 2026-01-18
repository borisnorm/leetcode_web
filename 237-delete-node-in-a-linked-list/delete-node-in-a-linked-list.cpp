/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
    
       if (!node)
         return;
    
       if (!node->next)
       {
          node = nullptr;
          return;
       }
        
       ListNode dummy(0);
       ListNode* dummy_head = &dummy;
       dummy_head->next = node;

       ListNode* pre = dummy_head;
       ListNode* cur = node;
       ListNode* nxt = nullptr;

       while (cur)
       {
          nxt = cur->next;
         
          if (nxt)
            cur->val = nxt->val;
          else
            pre->next = nullptr;
          
          pre = cur;
          cur = cur->next;
       }
        
    }
};