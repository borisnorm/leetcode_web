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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
         if (!head)
           return nullptr;

         //return build(head, nullptr);  
         
         return build2(head);
    }

    TreeNode* build(ListNode* head, ListNode* tail)
    {
         if (head == tail)
           return nullptr;
       
         ListNode* slow = head;
         ListNode* fast = head->next;
        
         while (fast != tail && fast->next != tail)
         {
            slow = slow->next;
            fast = fast->next->next;
         }

         TreeNode* node = new TreeNode(slow->val);

         node->left  = build(head, slow);
         node->right = build(slow->next, tail);
        
         return node;
    }

    TreeNode* build2(ListNode* head)
    {
         if (!head)
           return nullptr;

        if (!head->next) 
           return new TreeNode(head->val); // 单节点直接返回，避免断链边界坑
       
         ListNode* slow = head;
         ListNode* fast = head;
        
         ListNode* pre = nullptr;
         while (fast && fast->next)
         {
            pre  = slow;
            slow = slow->next;
            fast = fast->next->next;
         }

         if (pre)
           pre->next = nullptr;

         TreeNode* node = new TreeNode(slow->val);

         node->left = (slow == head) ? nullptr : build2(head);
         //node->left = build2(head);
         node->right = build2(slow->next);
        
         return node;
    }
};