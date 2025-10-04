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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;

        if (!root)
          return res;
        
        preorder_traverse(root, res);

        return res;

    }

    void preorder_traverse(TreeNode* root, vector<int>& res)
    {
        if (!root)
          return;

        res.push_back(root->val);
        preorder_traverse(root->left, res);
        preorder_traverse(root->right, res);
    }
};