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