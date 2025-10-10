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
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        
        if (!root)
          return 0;
    
        maxDepth(root);

        return diameter; 
    }

    int maxDepth(TreeNode* root)
    {
        if (!root)
          return 0;

        int leftdepth = maxDepth(root->left);
        int rightdepth = maxDepth(root->right);

        diameter = max(diameter, (leftdepth + rightdepth));

        return max(leftdepth, rightdepth) + 1;
    }
};