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
    bool isValidBST(TreeNode* root) {
        if (!root)
          return true;
        
        return _isValidBST(root, nullptr, nullptr);
        
    }

    bool _isValidBST(TreeNode* root, TreeNode* left, TreeNode* right)
    {
        if (!root)
          return true;
        
        if (left)
          if (root->val <= left->val)
            return false;
        
        if (right)
          if (root->val >= right->val)
            return false;
           
        bool isLeftBST = _isValidBST(root->left, left, root);
        bool isRightBST = _isValidBST(root->right, root, right); 

        return isLeftBST && isRightBST;
       
    }
 };


/*
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        if (!root)
          return false;
 
        return _isValidBST(root, nullptr, nullptr);

    }

    bool _isValidBST(TreeNode* node, TreeNode* low, TreeNode* high)
    {
        if (!node)
          return true;

        if (low && node->val <= low->val)
          return false;
        
        if (high && node->val >= high->val)
          return false;

        return _isValidBST(node->left, low, node) && _isValidBST(node->right, node, high);
    }
};

*/