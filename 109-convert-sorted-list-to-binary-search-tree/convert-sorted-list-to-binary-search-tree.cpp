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
    ListNode* cur = nullptr;
    TreeNode* sortedListToBST(ListNode* head) {
         if (!head)
           return nullptr;

         if (!head->next)
           return new TreeNode(head->val);

         ListNode* p = head;
         int n = 0;
         while (p)
         {
            n++;
            p = p->next;
         }

         cur = head;
         return build(0, n-1);
    }

    TreeNode* build(int l, int r)
    {
       //inorder bst
       if (l > r)
         return nullptr;
        
       int mid = l + (r-l)/2;

       TreeNode* left = build(l, mid-1);

       TreeNode* root = new TreeNode(cur->val);
       cur = cur->next;

       root->left = left;
       root->right = build(mid+1, r);

       return root;
    }
};


/*
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
         if (!head)
           return nullptr;

         if (!head->next)
           return new TreeNode(head->val);
        
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

         //slow 已经被用掉, 如何 slow==head, 也就是只有一个节点的时候
         //那就是错误了
         node->left = (slow == head) ? nullptr : sortedListToBST(head);
         node->right = sortedListToBST(slow->next);
        
         return node;
    }

};
*/

/*
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
         if (!head)
           return nullptr;

        return build(head, nullptr);  
    }

    TreeNode* build(ListNode* head, ListNode* tail)
    {
         if (head == tail)
           return nullptr;
       
         ListNode* slow = head;
         ListNode* fast = head;
        
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
};
*/