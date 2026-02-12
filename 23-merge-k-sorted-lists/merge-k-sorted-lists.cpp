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

        // n 是 奇数  11
        // interval  1, 2, 4, 8
        //            Merge 外    从 2 跳到 4 需要 2 * interval, 进行滚动 合并
        // interval = 1: [0, 1] [2, 3]-- 2*interval -->[4, 5] [6, 7] [8, 9] [10]
        // interval = 2: [0, 2] [4, 6] [8, 10]
        // interval = 4: [0, 4] [8]
        // interval = 8: [0, 8]
        //            Merge 内   需要 i, i + interval 才可以
        // 公式 很明显是    lists[i] = mergeTwo(list[i], list[i+interval]);
        // 正因为这个 interval 我们才需要将 interval 初始化 为 1; 
        while (interval < n)
        {
           for (int i = 0; i + interval < n; i+= interval *2)
             lists[i] = mergeTwo(lists[i], lists[i+interval]);
        
           interval *= 2;
        }

        return lists[0];
    }

    ListNode* mergeTwo(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(0);
        ListNode* cur = &dummy;

        while (l1 && l2)
        {

           if (l1->val <= l2->val)
           {
             cur->next = l1;
             l1 = l1->next;
           }
           else
           {
             cur->next = l2;
             l2 = l2->next;
           }

          cur = cur->next;

        }

        cur->next = l1 ? l1 : l2;

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
        ListNode* cur = &dummy;

        while (!pq.empty())
        {
           ListNode* node = pq.top();
           pq.pop();

           cur->next = node;
           cur = cur->next;

           if (node->next)
             pq.push(node->next);
        }

        cur->next = nullptr;

        return dummy.next;
    }

    */
};