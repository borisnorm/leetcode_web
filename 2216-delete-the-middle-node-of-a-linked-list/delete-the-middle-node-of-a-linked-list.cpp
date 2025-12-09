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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next)
          return nullptr;

        ListNode  dummy;
        ListNode* dummy_head = &dummy;
        dummy_head->next = head;

        ListNode* slow = dummy_head;
        ListNode* fast = dummy_head->next;

        while (fast && fast->next)
        {
           slow = slow->next;
           fast = fast->next->next;
        }

        ListNode* pre = slow;
        ListNode* cur = slow->next;
        ListNode* nxt = cur->next;

        pre->next = nxt;

        delete cur;

        return dummy_head->next;

    }
};