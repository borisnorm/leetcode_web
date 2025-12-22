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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
               if (!head || !head->next)
                 return head;
                
               ListNode dummy(0);
               ListNode* dummy_head = &dummy;
               dummy_head->next = head;
               
               ListNode* pre = dummy_head;
               ListNode* cur = pre->next;
               ListNode* nxt = nullptr;
  
               int step = 1;
               while(cur)
               {
                  if (step == left)
                    break;
                
                  step++;
                  pre = cur;
                  cur = cur->next;
               }
              ListNode* newHead = cur;
              if (!cur)
                return head;

              while(cur)
              {
                 nxt = cur->next;
                
                 if (step == right)
                   break;
                
                 step++;
                 cur = cur->next;  
              }

              
              if (cur)
              {
                ListNode* newHeadtail = cur;
                newHeadtail->next = nullptr;
              }

              pre->next = reverseList(newHead);
              newHead->next = nxt;

              return dummy.next;
    }

    ListNode* reverseList(ListNode* head)
    {
        if (!head || !head->next)
          return head;
        

        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* nxt = nullptr;

        while (cur)
        {
           nxt = cur->next;

           cur->next = pre;
           pre = cur;

           cur = nxt;
        }
        
        return pre;
    }
};