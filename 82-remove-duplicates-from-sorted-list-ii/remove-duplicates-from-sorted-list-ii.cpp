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
    
      ListNode dummy(0);
      ListNode* dummy_head = &dummy;
      dummy_head->next = head;

      ListNode* pre = dummy_head;
      ListNode* cur = head;

      while (cur)
      {
         if (cur->next && cur->val == cur->next->val)
         {
            int dupVal = cur->val;

            while (cur && cur->val == dupVal)
              cur = cur->next;
            
            // 情况 1: cur->val != dupVal;
            // 情况 2: cur == nullptr;
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
/*
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (!head || !head->next)
          return head;

        ListNode dummy(0);
        ListNode* dummy_head = &dummy;
        dummy_head->next = head;

        ListNode* pre = dummy_head;
        ListNode* slow = head;
        ListNode* fast = head->next;
       
        bool isDuplicate = false;
        while (fast)
        {
           if (fast->val != slow->val)
           {
              if (!isDuplicate)
              {
                pre = slow;
                slow = slow->next;
                fast = fast->next;
              }
              else
              {
                 //skip to the latest different fast
                 pre->next = fast;
               
                 //slow as the new fast
                 slow = fast;
                 fast = fast->next;
                 isDuplicate = false;
              }
           }
           else
           {
              fast = fast->next;
              isDuplicate = true;
           }
        }

        if (isDuplicate)
          pre->next = fast;
        
        return dummy.next;
    }
    */
};