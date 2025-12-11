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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
          return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

       //            |--------------|
       //            |   [3] + [4]  |
       //  (1) --  (2) --- (3) --- (4) --- (5)
       //   |   [1] + [2]   ^
       //   |---------------|
 
        //odd 永远在 even 的后面, even 先到 nullptr, 保证了 odd 不会为 nullptr,而是最后一个节点,进而可以 链接新的 even list
        while (even && even->next)
        {
           odd->next = even->next;
           odd = odd->next;
           
           even->next = odd->next;
           even = even->next;
        }

        odd->next = evenHead;

        return head;
    }

/*
    ListNode* oddEvenList(ListNode* head) {
         if (!head || !head->next)
           return head;

          ListNode* odd = head;
          ListNode* even = head->next;
          
          ListNode* evenHead = even;

          while (even && even->next)
          {
              
              odd->next = even->next;
              odd = odd->next;
              // 1->2->3 

              even->next = odd->next;
              even = even->next;
          }

          odd->next = evenHead;

          return head;
    }
    */
};