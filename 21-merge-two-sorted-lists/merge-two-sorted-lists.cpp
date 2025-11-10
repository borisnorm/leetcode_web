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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
          return list2;
        if (!list2)
          return list1;

        
        ListNode  dummy;
        ListNode *dummy_head = &dummy;        
        ListNode *cur = dummy_head;

        ListNode *l1 = list1;
        ListNode *l2 = list2;

        while(l1 && l2)
        {
           if (l1->val < l2->val)
           {
              cur->next = l1;
              l1 = l1->next;
           }
           else
           {
              cur->next = l2;
              l2 = l2->next;
           }

            cur = cur->next;  // l1/l2 没有与 cur 同步, 因为 l1/l2 在 赋值给 cur->next 后,自己又向后走了 l1 = l1->next;
        }

        if (!l1)
          cur->next = l2;
        
        if (!l2)
          cur->next = l1;

        return dummy_head->next;

    }
};