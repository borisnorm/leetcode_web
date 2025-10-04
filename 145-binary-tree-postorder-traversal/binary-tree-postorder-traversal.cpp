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

         stack<TreeNode*> nodes_stack;
         stack<TreeNode*> postorder_nodes_stack;
         
         nodes_stack.push(root);
         
         while(!nodes_stack.empty())
         {
            TreeNode* node = nodes_stack.top();
            nodes_stack.pop();

            postorder_nodes_stack.push(node);

            if (node->left)
              nodes_stack.push(node->left);
            
            if (node->right)
              nodes_stack.push(node->right);
         }

         while (!postorder_nodes_stack.empty())
         {
            TreeNode* node = postorder_nodes_stack.top();
            postorder_nodes_stack.pop();

            res.push_back(node->val);
         }

         return res;

    }
};