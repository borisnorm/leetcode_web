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
    bool checkTree(TreeNode* root) {
        if (!root)
          return false;
        
        if (!(root->left && root->right))
          return false;
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if (left->val + right->val != root->val)
          return false;
        
        return true;
    }
};