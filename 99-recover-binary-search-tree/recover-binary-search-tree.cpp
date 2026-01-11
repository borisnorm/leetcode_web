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
    void recoverTree(TreeNode* root) {
         TreeNode* cur = nullptr;
         TreeNode* pre = nullptr;
         TreeNode* first = nullptr;
         TreeNode* second = nullptr;


         stack<TreeNode*> st;
         cur = root;
         
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

         swap(first->val, second->val);
    }
};