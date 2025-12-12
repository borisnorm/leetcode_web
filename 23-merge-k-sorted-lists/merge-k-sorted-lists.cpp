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
        if (lists.empty())
          return nullptr;
        
        int interval = 1;
        int n = (int)lists.size();

        while (interval < n)
        {
           for (int i = 0; i + interval < n; i+= interval *2)
             lists[i] = mergeTwo(lists[i], lists[i+interval]);
        
           interval *= 2;
        }

        return lists[0];
    }

    ListNode* mergeTwo(ListNode* a, ListNode* b)
    {
        ListNode dummy(0);
        ListNode* dummy_head = &dummy;

        while (a && b)
        {

           if (a->val <= b->val)
           {
             dummy_head->next = a;
             a = a->next;
           }
           else
           {
             dummy_head->next = b;
             b = b->next;
           }

           dummy_head = dummy_head->next;

        }

        dummy_head->next = a ? a : b;

        return dummy.next;
    }

/*
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
    }

    */
};