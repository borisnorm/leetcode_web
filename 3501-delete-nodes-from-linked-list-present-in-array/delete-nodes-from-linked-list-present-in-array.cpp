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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> nums_set(nums.begin(), nums.end());

        ListNode dummy(0);
        dummy.next = head;

        ListNode* pre = &dummy;
        ListNode* cur = head;
        while (cur)
        {
           if (nums_set.count(cur->val))
           {
              pre->next = cur->next;
              cur = cur->next;
           }
           else
           {
             pre = cur;
             cur = cur->next;
           }

        }

        return dummy.next;
    }
};