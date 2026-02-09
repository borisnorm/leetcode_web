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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
          return false;
        stack<pair<TreeNode*, int>> st;
        st.push({root, targetSum});

        while(!st.empty())
        {
           auto [cur, targetSum] = st.top();
           st.pop();

           if (!cur->left && !cur->right && targetSum == cur->val)
             return true;
           
           if (cur->right)
             st.push({cur->right, (targetSum-cur->val)});
        
           if (cur->left)
             st.push({cur->left, (targetSum-cur->val)});
        }

        return false;
    }
};
/*
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
          return false;
        
        int rootVal = root->val;
        if (!root->left && !root->right && rootVal == targetSum)
          return true;

        bool leftFound = hasPathSum(root->left, targetSum-rootVal);
        bool rightFound = hasPathSum(root->right, targetSum-rootVal);

        return leftFound || rightFound;
    }
};
*/