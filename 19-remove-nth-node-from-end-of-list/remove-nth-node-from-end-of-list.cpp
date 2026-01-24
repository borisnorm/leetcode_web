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

        ListNode* slow = dummy_head;
        ListNode* fast = dummy_head;

        // get 倒数 第 n + 1 个节点 也就是 n 的前一个节点
        for (int i = 0; i < n + 1; i++)
        {
           if (!fast)
             return head;
           fast = fast->next;
        }

        while (fast)
        {
           slow = slow->next;
           fast = fast->next;
        }

        ListNode* del = slow->next;
        slow->next = del->next;

        delete del;

        return dummy.next;
    }
};

/*
 class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         if (!head)
           return head;

         ListNode  dummy;
         ListNode* dummy_head = &dummy;
         dummy_head->next = head;

         int cnt = 0;
         ListNode* cur = head;
         while (cur)
         {
            cnt++;
            cur = cur->next;
         }

         cur = dummy_head;
         for (int i = 0; i < cnt - n; i++)
         {
            cur = cur->next;
         }

         ListNode* del = cur->next;
         cur->next = del->next;
         delete del;

         return dummy.next;

         
    }
 };
*/

/*
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
       // 0表示从 dummy 开始的节点 
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
*/