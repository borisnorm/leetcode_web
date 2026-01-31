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
    int getLeftDepth(TreeNode* root)
    {
        int level = 0;
        while (root)
        {
            level++;
            root = root->left;
        }
        return level;
    }

    int getRightDepth(TreeNode* root)
    {
        int level = 0;
        while (root)
        {
            level++;
            root = root->right;
        }
        return level;
    }

    int countNodes(TreeNode* root) {
        if (!root)
            return 0;

        // 注意：这里从 root 开始算
        int leftDepth = getLeftDepth(root);
        int rightDepth = getRightDepth(root);

        if (leftDepth == rightDepth)
        {
            // 高度 = leftDepth，节点数 = 2^h - 1
            return (1 << leftDepth) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
