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
        ListNode dummy;
        ListNode *dummy_head=&dummy;
        dummy_head->next=head;

        if (!head || !head->next)
          return head;

        ListNode* left  = dummy_head;
        ListNode* iter  = head;
        ListNode* right = head->next;

        while(right)
        {
          if (iter->val != right->val)
          {
             right = right->next;
             iter  = iter->next;
             left  = left->next;
          }
          else
          {

            // move to the most right
            while (right && iter->val == right->val)
              right = right->next;

            // right possible nullptr
            
            //delete duplicate
            while (iter != right)
            {
               // å æ iter ä¹å°±æ¯ leftmost é£ä¸ªèç¹
               // è¿é left ä¸ç´æ²¡æ update è·æ°, å§ç»ä¿æåå¼
               left->next = iter->next;
               iter->next = nullptr;
               //delete iter;

               iter = left->next;
            }
            
            // right move one more step
            if (right)
            {
              iter = right; 
              right = right->next;
            }
          }            
        }

        return dummy_head->next;
    }
};