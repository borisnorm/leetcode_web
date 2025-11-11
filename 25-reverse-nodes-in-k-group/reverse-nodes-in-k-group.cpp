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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k <= 1)
          return head;
        
        ListNode* check = head;
        for (int i = 0; i < k; i++)
        {
          if (!check)
            return head;
          check = check->next;   
        }

        ListNode * pre = nullptr;
        ListNode * cur = head;
        ListNode * next = nullptr;

        for (int i = 0 ; i < k ; i++)
        {
           next = cur->next;
           cur->next = pre;
           pre = cur;
           cur = next;  
        }

        head->next = reverseKGroup(cur, k);

        return pre;
    }

};

