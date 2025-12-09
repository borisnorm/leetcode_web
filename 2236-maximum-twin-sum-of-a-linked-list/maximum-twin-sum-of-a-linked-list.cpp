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
    int pairSum(ListNode* head) {
        
        if (!head || !head->next)
          return 0;
        
        stack<int> st;

        ListNode dummy(0);
        ListNode* dummy_head = &dummy;

        dummy_head->next = head;

        ListNode* slow = dummy_head;
        ListNode* fast = head;

        while (fast && fast->next)
        {
           slow = slow->next;
           st.push(slow->val);

           fast = fast->next->next;
        }
        
        int maxSum = INT_MIN;
        int sum = 0;
        while(slow)
        {
           slow = slow->next;
           if (!st.empty() && slow)
           {
             sum = slow->val + st.top();
             st.pop();

             maxSum = max(maxSum, sum);
           }
        }

        return maxSum;
    }
};