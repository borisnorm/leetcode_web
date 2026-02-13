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
          
        //带约束传递的前序遍历
        return _isValidBST(root, nullptr, nullptr);
        
    }

    bool _isValidBST(TreeNode* root, TreeNode* low, TreeNode* high)
    {
        if (!root)
          return true;
        
        if (low && root->val <= low->val)
            return false;
        
        if (high && root->val >= high->val)
            return false;
           
        bool isLeftBST = _isValidBST(root->left, low, root);
        bool isRightBST = _isValidBST(root->right, root, high); 

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