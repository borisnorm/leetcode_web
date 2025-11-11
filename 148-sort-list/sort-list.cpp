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
    ListNode* sortList(ListNode* head) {

         if (!head || !head->next)
           return head;

         ListNode* slow = head;
         ListNode* fast = head->next;

         // slow in mid or mid left part
         while(fast && fast->next)
         {
            slow = slow->next;
            fast = fast->next->next;
         }    
           
         ListNode* right = slow->next;
         slow->next = nullptr;
         ListNode* left = head; 
       
         left = sortList(left);
         right = sortList(right);

         ListNode* merged = mergeSort(left, right);

         return merged;
    }

    ListNode* mergeSort(ListNode* l1, ListNode* l2)
    {
        if (!l1 && !l2)
          return nullptr;

        ListNode  dummy(0);
        ListNode* dummy_head = &dummy;
        ListNode* tail = dummy_head;

        while (l1 && l2)
        {
          if (l1->val < l2->val)
          {
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
          }
          else
          {
            tail->next = l2;
            l2 = l2->next;
            tail = tail->next;
          }
        }

        tail->next  = l1 ? l1 : l2;

        return dummy_head->next;
    }

};