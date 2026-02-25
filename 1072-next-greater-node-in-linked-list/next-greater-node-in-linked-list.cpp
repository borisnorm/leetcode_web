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