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
    bool isBalanced(TreeNode* root) {
        if (!root)
          return true;
        
       int leftDepth = getDepth(root->left);
       int rightDepth = getDepth(root->right);

       if (abs(leftDepth - rightDepth) > 1)
         return false;
    
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int getDepth(TreeNode* root)
    {
       if (!root)
         return 0;
      
       int leftDepth = getDepth(root->left);
       int rightDepth = getDepth(root->right);

       return max(leftDepth, rightDepth) + 1;
    }
};