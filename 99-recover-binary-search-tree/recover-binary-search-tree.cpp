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

class Solution{
  public: 
    void recoverTree(TreeNode* root)
    {
      TreeNode* cur = root;
      TreeNode* prev = nullptr;

      TreeNode* first = nullptr;
      TreeNode* second = nullptr;

      while(cur)
      {
         //如果没有左子树
         if (cur->left == nullptr)
         {
            detect(prev, cur, first, second);
            prev = cur;

            cur = cur->right;
         }
         else
         {
            TreeNode* pred = cur->left;
            while (pred->right && pred->right != cur)
              pred = pred->right;
            
            //没有右子树的
            if (pred->right == nullptr)
            {
              pred->right = cur;
              cur = cur->left;
            }
            else
            {
                pred->right = nullptr;

                detect(prev, cur, first, second);
                prev = cur;

                cur = cur->right;
            }
         }
      }
      if (first && second)
       swap(first->val, second->val);
    }

    void detect(TreeNode* prev, TreeNode* cur, TreeNode*& first, TreeNode*& second)
    {
      if (prev && prev->val > cur->val)
      {
         if (!first)
           first = prev;
         
          second = cur;
      }
    }
};

/*
class Solution {
public:
    void recoverTree(TreeNode* root) {
        if (!root)
          return;
        
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        dfs(root, first, second);

        if (first && second)
          swap(first->val, second->val);
    }

    TreeNode* prev = nullptr;
    void dfs(TreeNode* root, TreeNode*& first, TreeNode*& second)
    {
        if (!root)
          return;
        
        //left
        dfs(root->left, first, second);

        //root 
        if (prev)
        {
           if (prev->val > root->val)
           {
              if (!first)
                first = prev;
            
              second = root;
           }
        }
        prev = root;

        //right;

        dfs(root->right, first, second);
    }
};
*/

/*
class Solution {
public:
    void recoverTree(TreeNode* root) {

         TreeNode* first = nullptr;
         TreeNode* second = nullptr;

         stack<TreeNode*> st;
         TreeNode* cur = root;
         TreeNode* pre = nullptr;
         
         while (cur || !st.empty())
         {
            while (cur)
            {
               st.push(cur);
               cur = cur->left;
            }

            cur = st.top();
            st.pop();

            //中序遍历 BST 单调递增, pre < cur 才对
            if (pre && pre->val > cur->val)
            {
               if (!first)
                 first = pre;

               second = cur; 
            }
            
            pre = cur;

            cur = cur->right;
         }

         if (first && second)
           swap(first->val, second->val);
    }
};
*/