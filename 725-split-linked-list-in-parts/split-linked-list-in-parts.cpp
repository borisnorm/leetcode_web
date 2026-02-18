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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // k + ( k + 1) + (k+2) + (k + n - 1) 

        vector<ListNode*> res(k, nullptr);
        ListNode* prob = head;
        int cnt = 0;
        while (prob)
        {
           cnt++;
           prob = prob->next;
        }

        int base = cnt / k;
        int remain = cnt % k;

        ListNode* cur = head;
        for (int i = 0; i < k && cur; i++)
        {
           res[i]=cur;
           //res.push_back(cur);  //是追加到末尾，不是覆盖已有位置 造成size = k+1, k+2. 
           int sz = base + (remain > 0 ? 1 : 0);
           remain--;

           for (int j = 0; j < sz-1; j++)
              cur = cur->next;
           
           ListNode* nxt = cur->next;
           cur->next = nullptr;
           cur = nxt;
        }

        return res;
         
    }
};