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
    int sumNumbers(TreeNode* root) {
        if (!root)
          return 0;

        return sumNumbersFromRoot(root, 0);
    }

    int sumNumbersFromRoot(TreeNode* root, int val)
    {
        if (!root)
          return 0;   // 如果左右子节点为空, 应该返回当前的 val
        
        val = val * 10 + root->val;
        if (!root->left && !root->right)
          return val;

        int leftVal = sumNumbersFromRoot(root->left, val);
        int rightVal = sumNumbersFromRoot(root->right, val);

        return leftVal + rightVal;
    }
};