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
        
        // 用来检测, 最后的节点能否 进行 k 个反转的, 如果不行就 返回现在的 head
        ListNode* check = head;
        for (int i = 0; i < k; i++)
        {
          if (!check)
            return head;
          check = check->next;   
        }

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
        head->next = reverseKGroup(cur, k);

        return pre;
    }

};

