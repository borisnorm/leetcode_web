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
    ListNode* removeNodes(ListNode* head) {

        ListNode* rHead = reverseList(head);

        ListNode dummy(0);
        ListNode* prev = rHead;
        ListNode* cur = rHead->next;
        int maxVal = rHead->val;
        while (cur)
        {
           if (maxVal > cur->val)
           {
              prev->next = cur->next;
              cur = cur->next;
           }
           else
           {
              maxVal = cur->val;
              prev = cur;
              cur = cur->next;
           }
        }

        return reverseList(rHead);
    }

    ListNode* reverseList(ListNode* head)
    {
        if (!head)
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
/* 
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        
        // Time: O(n)
        // Space: O(n)
        ListNode* cur = head;
        stack<ListNode*> st;
        while (cur)
        {
           while (!st.empty() && cur->val > st.top()->val)
             st.pop();
           
           st.push(cur);
           cur = cur->next;
        }

        ListNode* pre = nullptr;
        while(!st.empty())
        {
           cur = st.top();
           st.pop();
           
           cur->next = pre;
           pre = cur;
        }

        return pre;
    }
};

*/