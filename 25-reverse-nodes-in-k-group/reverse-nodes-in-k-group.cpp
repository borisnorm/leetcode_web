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
        
        int cnt = 0;
        ListNode* prob = head;
        while(prob && cnt < k)
        {
           cnt++;
           prob = prob->next;
        }

        // k is too big that prob has became null
        if (cnt < k)
          return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* dummy_head = &dummy;

        ListNode* pre = dummy_head;
        ListNode* cur = head;
        ListNode* nxt = nullptr;

        while(true)
        {
           ListNode* kth = pre;
           for (int i = 0; i < k && kth; i++)
           {
              kth = kth->next;
           }

           if (!kth)
             break;
        
           cur = pre->next;
           for (int i = 1; i < k; i++)
           {
              nxt = cur->next;
              cur->next = nxt->next;
              nxt->next = pre->next;

              pre->next = nxt;
           }

           pre = cur;
        }

        return dummy.next;
        
    }
};

 /*

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k <= 1)
          return head;
        
        // 用来检测, 最后的节点能否 进行 k 个反转的, 如果不行就 返回现在的 head
        ListNode* cur = head;
        for (int i = 0; i < k && cur; i++)
        {
          check = check->next;   
        }

        if (i < k)
          return head;

        // 1->2->3->4->5
        // 2->1->nullptr,   3->4->5
        //
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

        // 2->1->[反转后 3->4->5] 实际上就是 2->1->4->3-5
        // 在 reverseGroup 里面 新的 head 变成了 cur[3]
        head->next = reverseKGroup(cur, k);

        return pre;
    }

};

*/

