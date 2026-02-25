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
    vector<int> nextLargerNodes(ListNode* head) {
        if (!head)
          return {};
        
        stack<int> st;
        vector<int> res;

        ListNode* cur = head;

        while (cur)
        {
          
          while (!st.empty() && cur->val > res[st.top()])
          {
              int preIdx = st.top();
              st.pop();

              res[preIdx] = cur->val;
          }

          res.push_back(cur->val);
          int idx = res.size()-1;

          st.push(idx);

          cur = cur->next;
        }

        while(!st.empty())
        {
           res[st.top()] = 0;
           st.pop();
        }

        return res;
    }
};
 /*
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if (!head)
          return {};

        vector<int> res;

        ListNode* cur = head;
        while(cur)
        {
            ListNode* nxt = cur->next;
            while(nxt && cur->val >= nxt->val)
              nxt = nxt->next;

            if (nxt)
              res.push_back(nxt->val);
            else
              res.push_back(0);

            cur = cur->next;
        } 
    
        return res;
    }
};

*/