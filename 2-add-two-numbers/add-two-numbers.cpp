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
           
         int sum = 0;
         int carry = 0;

         ListNode  dummy;
         ListNode* dummy_head = &dummy;
         ListNode* cur = dummy_head;
         

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
           carry = sum/10;
           sum = sum%10;
            
           cur->next = new ListNode(sum);
           cur = cur->next;

         }

        // if (carry)
         //  cur->next = new ListNode(carry);

        return dummy_head->next;
    }
};