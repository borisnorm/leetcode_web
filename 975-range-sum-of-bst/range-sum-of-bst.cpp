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

    // 经典 BST 剪枝
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root)
          return 0;

        int sum = 0;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty())
        {
           TreeNode* cur = st.top();
           st.pop();

           if (cur->val < low)
           {
              if (cur->right)
                st.push(cur->right);
           }
           else if (cur->val > high)
           {
              if (cur->left)
                st.push(cur->left);
           }
           else
           {
              if (cur->left)
                st.push(cur->left);
        
              sum += cur->val;

              if (cur->right)
                st.push(cur->right);
           }
           
        }

        return sum;
    }

/*
    正确
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root)
          return 0;

        int sum = 0;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty())
        {
           TreeNode* cur = st.top();
           st.pop();

           if (cur->val >= low)
           {
              if (cur->left)
                st.push(cur->left);
           }
        
          if (low <= cur->val && cur->val <= high)
            sum += cur->val;

           if (cur->val <= high)
           {
              if (cur->right)
                st.push(cur->right);
           }
           
        }

        return sum;
    }

    */

/*
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root)
          return 0;

        int sum = 0;
        traverseBST(root, low, high, sum);
        return sum;
    }

    void traverseBST(TreeNode* root, int low, int high, int& sum)
    {
        if (!root)
          return;
        
        if  (root->left && root->val >= low)
          traverseBST(root->left, low, high, sum);

        if (low <= root->val && root->val <= high)
          sum += root->val;

        if (root->right && root->val <= high)
          traverseBST(root->right, low, high, sum);
    }

    */
};