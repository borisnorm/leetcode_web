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
    
    ListNode* head;
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int res = 0;
        int cnt = 0;
        
        ListNode* cur = head;
        while(cur)
        {
           // cnt 要先加 才可以
           cnt++;

           if (rand() % cnt == 0)
           {
              res = cur->val;
           }

           cur = cur->next;
        }

        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */