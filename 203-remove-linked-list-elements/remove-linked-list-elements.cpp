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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
          return nullptr;
        
        ListNode  dummy;
        ListNode* dummy_head = &dummy;
        dummy_head->next = head;

        ListNode* pre = dummy_head;
        ListNode* cur = dummy_head->next;
        ListNode* nxt = nullptr;

        while(cur)
        {
           if (cur->val == val)
           {
              nxt = cur->next;
              
              pre->next = nxt;
              delete cur;

              // 删除完后, cur 更新为 nxt 
              cur = nxt;
           }
           else
           {
             pre = cur;
             cur = cur->next;
           }
        }

        return dummy_head->next;
    }
};

/*

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* cur = &dummy;

        while (cur->next) {
            if (cur->next->val == val) {
                cur->next = cur->next->next; // 删除 cur->next
            } else {
                cur = cur->next; // 正常前进
            }
        }

        return dummy.next;
    }
};

*/