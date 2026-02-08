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

    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);

        TreeNode* prev = nullptr;
        while (!st.empty())
        {
           TreeNode* cur = st.top();
           st.pop();

           if (prev)
           {
             prev->right = cur;
             prev->left = nullptr;
           }

           if (cur && cur->right)
            st.push(cur->right);
        
           if (cur && cur->left)
             st.push(cur->left);

           prev = cur;
        }
    }
};
/*
class Solution {
public:
    TreeNode* prev = nullptr;
    void flatten(TreeNode* root) {
        if (!root)
          return;
        
        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left   = nullptr;

        prev = root;
    }
};
*/