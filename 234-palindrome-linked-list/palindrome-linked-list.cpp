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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next)
        {
           slow = slow->next;
           fast = fast->next->next;
        }

        if (fast)
          slow = slow->next;

        ListNode* head2 = nullptr;
        head2 = reverseList(slow);

        ListNode* iter = head;
        ListNode* iter2 = head2;
        while (iter && iter2)
        {
          if (iter->val != iter2->val)
            return false;
            
          iter = iter->next;
          iter2 = iter2->next;
        }

        return true;
    }

    ListNode* reverseList(ListNode* node)
    {
        if (!node)
          return node;

        ListNode* head = node;
        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* nxt;

        //   1 -> 2 -> 3 -> null
        //.  2 -> 1 -> 3 -> null
 
        while(cur)
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