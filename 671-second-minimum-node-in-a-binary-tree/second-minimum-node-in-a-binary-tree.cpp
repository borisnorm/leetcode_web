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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root)
          return -1;

        long long secondMin = LONG_MAX;
        int minVal = root->val;

        dfs(root, minVal, secondMin);
        return (secondMin == LONG_MAX) ? -1 : secondMin;
    }

    void dfs(TreeNode* node, int minVal, long long& secondMin)
    {
        if (!node)
          return;

        if (node->val > minVal)
        {
            if (secondMin == -1 || (long long)node->val < secondMin)
              secondMin = (long long)node->val;
            return;
        }

        dfs(node->left, minVal, secondMin);
        dfs(node->right, minVal, secondMin);
    }
};