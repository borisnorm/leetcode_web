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
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || !head->next ||!k)
          return head;
        
        ListNode  dummy(0);
        ListNode* dummy_head = &dummy;
        dummy_head->next = head;

        int cnt = 0;
        ListNode* tail = head;
        while(tail)
        {
          cnt++;
          tail = tail->next;
        }
        
        k = k % cnt;
        if (!k)
          return head;

        ListNode* pre = findFromEnd(dummy_head, (k+1));
        ListNode* newHead = pre->next;

        tail = newHead;
        while (tail && tail->next)
          tail = tail->next;

        tail->next = head;
        head = newHead;

        pre->next = nullptr;
        
        return head;
    }

    ListNode* findFromEnd(ListNode* head, int k)
    {
       ListNode* fast = head;
       int cnt = 0;
       while (fast && cnt < k)
       {
          fast = fast->next;
          cnt++;
       }

       ListNode* slow = head;
       while (fast)
       {
          slow = slow->next;
          fast = fast->next;
       }   

       return slow;
    }
};