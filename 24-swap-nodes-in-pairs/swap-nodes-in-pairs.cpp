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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
          return head;

        ListNode  dummy(0);
        ListNode* dummy_head = &dummy;
        dummy_head->next = head;

        ListNode* pre = dummy_head;
        
        while(pre && pre->next && pre->next->next)
        {
           ListNode* a = pre->next;
           ListNode* b = a->next;

           a->next = b->next;
           b->next = a;
           pre->next = b;

           pre = a;
        }

        return dummy_head->next;
    }
};