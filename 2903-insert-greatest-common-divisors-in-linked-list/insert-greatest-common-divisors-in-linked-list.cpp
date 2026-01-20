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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next)
          return head;

        ListNode* pre = head;
        ListNode* cur = pre->next;

        while (cur)
        {
           int gcd = getGreatestCommonDivisor(pre->val, cur->val);
           ListNode* node = new ListNode(gcd);
        
           pre->next = node;
           node->next = cur;
           
           pre = cur;
           cur = cur->next;
        }

        return head;
    }


    int getGreatestCommonDivisor(int a, int b)
    {
        int maxGCD = 1;
        for (int i = 1; i <= min(a, b); i++)
        {
            if (a  % i == 0 && b % i == 0)
            {
                maxGCD = max(maxGCD, i);
            }
        }

        return maxGCD;
    }
};