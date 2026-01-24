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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)
          return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
               ListNode* slow2 = head;
               ListNode* fast2 = fast;
               while (slow2 != fast2)
               {
                  slow2 = slow2->next;
                  fast2 = fast2->next;
               }

               return slow2;
            }
        }

        return nullptr;
    }
};
 /*
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)
          return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
               break; 
            }
        }

        if (!fast || !fast->next)
          return nullptr;

        slow = head;
        while (slow != fast)
        {
           slow = slow->next;
           fast = fast->next;
        }

        return slow;
    }
};

*/