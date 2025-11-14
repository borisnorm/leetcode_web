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
    
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
          return 0;

        return countPath(root, (long long)targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

    int countPath(TreeNode* node, long long targetSum)
    {
      if (!node)
        return 0;

       int count = (node->val == targetSum) ? 1 : 0;

       count +=countPath(node->left, (targetSum - node->val));
       count +=countPath(node->right, (targetSum - node->val));

       return count;
    }
};