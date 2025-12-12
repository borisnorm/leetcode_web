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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        auto cmp = [](const ListNode* a, const ListNode* b){
            return a->val > b->val;
        };

        using T = ListNode*;
        priority_queue<T, vector<T>, decltype(cmp)> pq;

        for (auto* head : lists)
          if (head)
            pq.push(head);
        
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty())
        {
           ListNode* cur = pq.top();
           pq.pop();

           tail->next = cur;
           tail = tail->next;

           if (cur->next)
             pq.push(cur->next);
        }

        tail->next = nullptr;

        return dummy.next;

        // Merge-Sort
        // Combine
    }
};