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
    int max_sum = INT_MIN;
    int maxPathSum(TreeNode* root) {
       if (!root)
         return 0;

       nodePathSum(root);

       return max_sum;
    }

    int nodePathSum(TreeNode* node)
    {
        if (!node)
          return 0;

        int left_sum = max(nodePathSum(node->left), 0);
        int right_sum = max(nodePathSum(node->right), 0);

        int node_sum = left_sum + right_sum + node->val;

        max_sum = max(max_sum, node_sum);

        return max(left_sum, right_sum) + node->val;
    }


};