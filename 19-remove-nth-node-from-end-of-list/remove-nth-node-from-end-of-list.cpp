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

        //快慢指针解法
        // fast 跑 n + 1 个节点 , slow 与 fast 相差 n+1个节点
        for (int i = 0; i < n + 1; i++)
        {
           //if (!fast)
           //  return head;
           fast = fast->next;
        }

        // fast 比 slow 快 1 步
        // for(int i = 0; i < 1; i++)
        // slow 在倒数第1个节点 
        //
        // 1    2      3      4      5      (null)
        //                           ^        ^
        //                           |        |
        //                           slow     fast
        // fast 比 slow 快 2步
        // for(int i = 0; i < 1 + 1; i++)
        // n = 1 , 正好是 倒数第一个节点的 前一个节点
        //
        // 1    2      3      4      5      (null)
        //                    ^               ^
        //                    |               |
        //                    slow          fast
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
         //倒数第 n 个 = 正数第 (cnt - n + 1) 个
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