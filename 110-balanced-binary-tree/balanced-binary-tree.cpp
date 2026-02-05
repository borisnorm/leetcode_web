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
/*
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
          return true;

        if (getHeight(root) < 0)
          return false;

        return true;
    }

    int getHeight(TreeNode* root)
    {
       if (!root)
         return 0;
      
       //左树 先验模式
       int leftHeight = getHeight(root->left);
       if (leftHeight < 0)
         return -1;
       
       //右树 先验模式 所以 return 的时候就不需要在对 左右子树进行单独验证了
       int rightHeight= getHeight(root->right);
       if (rightHeight < 0)
         return -1;

       if (abs(leftHeight - rightHeight) > 1)
         return -1;

       return max(leftHeight, rightHeight) + 1;
    }
};
*/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
          return true;
        
        int leftHeight = getDepth(root->left);
        int rightHeight = getDepth(root->right);

        if (abs(leftHeight - rightHeight) > 1)
          return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int getDepth(TreeNode* root)
    {
        if (!root)
          return 0;
        
        return max(getDepth(root->left), getDepth(root->right)) + 1;

    }
};