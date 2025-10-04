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
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> res;
         if (!root)
           return res;
        
        postorder_traverse(root, res);
        return res;
    }

    void postorder_traverse(TreeNode* root, vector<int>& res)
    {
          if (!root)
            return;
          
          postorder_traverse(root->left, res);
          postorder_traverse(root->right, res);
          res.push_back(root->val);
    }
};