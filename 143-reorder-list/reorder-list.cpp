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
        
        while (left && right)
        {
           ListNode* leftnode = left;
           ListNode* rightnode = right;

           right = right->next;
           left = left->next;

           leftnode->next = rightnode;
           rightnode->next = left;
             
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
       
        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* nxt = nullptr;

        while (cur)
        {
           nxt = cur->next;
           cur->next = pre;
           pre = cur;
           head->next = nxt;

           cur = head->next;
        }

        return pre;
    }
};

