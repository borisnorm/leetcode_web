/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
          return nullptr;
        
        if (!p || !q)
          return root;
        
        TreeNode* cur = root;
        while (cur)
        {
            int val = cur->val;
            if (p->val < val && q->val < val)
              cur = cur->left;
            else if (p->val > val && q->val > val)
              cur = cur->right;
            else
              return cur;
        }

        //cur is already nulll at this time
        return nullptr;
        
    }
};
/*
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if (!root)
           return nullptr;
         if (!p && !q)
           return nullptr;
        
         TreeNode* cur = root;
         TreeNode* pre = nullptr;
         while (cur)
         {
             if (p && q)
             {
                int val = cur->val;
                if (p->val < val && q->val < val)
                  cur = cur->left;
                else if (p->val > val && q->val > val)
                  cur = cur->right;
                else
                // p->val > val && q->val < val
                // p->val < val && q->val > val
                // p->val > val && q->val < val
                // p->val < val && q->val > val
                  return cur;
             }
             else if (p || q)
             {
                TreeNode* target = p ? p : q;
                int val = cur->val;
                if (target->val < val)
                {
                  pre = cur;
                  cur = cur->left;
                }
                else if (target->val > val)
                {
                  pre = cur;
                  cur = cur->right;
                }
                else 
                {
                   return pre;
                }
             }
         }

         return nullptr;
         
    }
};
*/
/*
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
          return nullptr;

        if (p == root || q == root)
          return root;

        // top->down pre-order
        int val = root->val;
        if (p->val < val && q->val < val)
          return lowestCommonAncestor(root->left, p, q);

        if (p->val > val && q->val > val )
          return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};
*/
/*
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root || !p || !q)
             return nullptr;
        
        TreeNode* cur = root;
    
        while (cur)
        {
            int val = cur->val;
            if (p->val < cur->val && q->val < cur->val)
              cur = cur->left;
            else if (p->val > cur->val && q->val > cur->val)
              cur = cur->right;
            else
              return cur;
        }

        return nullptr;
    }
};

*/