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
    void reorderList(ListNode* head) {

        if (!head || !head->next)
          return;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* right = slow->next;
        slow->next = nullptr;

        ListNode* left = head;

        right = reverseList(right);
        
        while (right)
        {
           ListNode* left_nxt  = left->next;
           ListNode* right_nxt = right->next;

           left->next = right;
           right->next = left_nxt;

           left = left_nxt;
           right = right_nxt;
             
        }

        return;

    }

    ListNode* reverseList(ListNode* head)
    {
       if (!head || !head->next)
         return head;

        // head insert
       
        // (pre)1 (head)--> 2(cur)--> 3
        // (pre)2 -> 1(head)->3(cur)
       
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* nxt = nullptr;

        while (cur)
        {
           nxt = cur->next;
           cur->next = pre;
           pre = cur;
           cur = nxt;
        }

        return pre;
    }
};