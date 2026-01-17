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
    struct Info{
        bool isBst;
        int minVal;
        int maxVal;
        int size;
    };
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }

    Info dfs(TreeNode* node, int& res)
    {
        if (!node)
         {
            return {true, INT_MAX, INT_MIN, 0};
         }
         
         Info left = dfs(node->left, res);
         Info right = dfs(node->right, res);

         if (left.isBst && right.isBst && 
             left.maxVal < node->val && node->val < right.minVal)
         {
            int curSize = left.size + right.size + 1;

            res = max(res, curSize);

            return {true, 
                    left.size > 0 ? left.minVal : node->val,
                    right.size > 0 ? right.maxVal : node->val,
                    curSize};
         }

         return {false, 0, 0, 0};
    }
};