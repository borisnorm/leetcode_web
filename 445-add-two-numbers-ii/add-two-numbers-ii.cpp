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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            if (!l1 && !l2)
              return nullptr;
            
            stack<int> l1_st;
            stack<int> l2_st;

            ListNode* l1_cur = l1;
            ListNode* l2_cur = l2;

            while (l1_cur)
            {
               l1_st.push(l1_cur->val);
               l1_cur = l1_cur->next;
            }

            while(l2_cur)
            {
               l2_st.push(l2_cur->val);
               l2_cur = l2_cur->next;
            }

            int carry = 0;
            int sum = 0;

            ListNode* pre = nullptr;

            while(!l1_st.empty() || !l2_st.empty() || carry)
            {
               int l1_val = 0;
               int l2_val = 0;

               if (!l1_st.empty())
               {
                  l1_val = l1_st.top();
                  l1_st.pop();
               }

               if (!l2_st.empty())
               {
                  l2_val = l2_st.top();
                  l2_st.pop();
               }
               
               sum = l1_val + l2_val + carry;

               carry = sum/10;
               sum = sum%10;
            
               ListNode* node = new ListNode(sum);
               node->next = pre;
               pre = node;
               // h - 1
               // h - 2 - 1(pre)
            }

            return pre;
    }
};
/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2)
          return nullptr;
        
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode dummy(0);
        ListNode* cur = &dummy;

        int carry = 0;
        int sum = 0;

        while(l1 || l2 || carry)
        {
           int l1_val = 0;
           int l2_val = 0;

           if (l1)
           {
              l1_val = l1->val;
              l1 = l1->next;
           }

           if (l2)
           { 
              l2_val = l2->val;
              l2 = l2->next;
           }

           sum = l1_val + l2_val + carry;
           carry = sum/10;
           sum = sum%10;
           
           cur->next = new ListNode(sum);
           cur = cur->next;
        }

        dummy.next = reverseList(dummy.next);

        return dummy.next;
    }

    ListNode* reverseList(ListNode* head)
    {
        if (!head || !head->next)
          return head;

        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* nxt = nullptr;

        while(cur)
        {
           nxt = cur->next;
           cur->next = pre;
           pre = cur;
           cur = nxt;
        }

        return pre;

    }
};
*/