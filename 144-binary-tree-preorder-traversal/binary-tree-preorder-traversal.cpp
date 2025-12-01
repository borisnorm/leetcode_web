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
        
        stack<TreeNode*> nodes_stack;
        nodes_stack.push(root);

        while (!nodes_stack.empty())
        {
           TreeNode* node = nodes_stack.top();
           nodes_stack.pop();

           res.push_back(node->val);

           if (node->right)
             nodes_stack.push(node->right);
           if (node->left)
             nodes_stack.push(node->left);
        }

        return res;

    }
};