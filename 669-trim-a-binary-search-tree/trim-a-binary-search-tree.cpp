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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
         if (!root)
           return nullptr;

        // 当前节点值太小，整个左子树都太小，只需要在右子树中找
         if (root->val < low)
           return trimBST(root->right, low, high);
        
        // 当前节点值太大，整个右子树都太大，只需要在左子树中找
         if (root->val > high)
           return trimBST(root->left, low, high);

        // 当前节点在范围内，保留它，递归修剪左右子树
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};