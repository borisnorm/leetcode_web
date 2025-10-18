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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
          return head;

        ListNode dummy(0);
        ListNode* dummy_head = &dummy;
        dummy_head->next = head;

        ListNode* preNth = findFromEnd(dummy_head, (n+1));
        if (!preNth || !preNth->next)
          return dummy_head->next;

        preNth->next = preNth->next->next;

        return dummy_head->next;
    }

    ListNode* findFromEnd(ListNode* head, int n)
    {
       ListNode* fast = head;
       for (int i = 0; i < n; i++)
         fast = fast->next;

       ListNode* slow = head;
       while (fast)
       {
          slow = slow->next;
          fast = fast->next;
       }

       return slow;
    }
};