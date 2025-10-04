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
        TreeNode* last = nullptr;
        TreeNode* cur= root;

        while (cur || !nodes_stack.empty())
        {
          if (cur)
          {
            nodes_stack.push(cur);

            cur = cur->left;
          } 
          else
          {
              TreeNode* node = nodes_stack.top();
              if (node->right && node->right != last)
              {
                 cur = node->right;
              }
              else
              {
                  nodes_stack.pop();
                  
                  res.push_back(node->val);

                  last = node;
              }
          }
        }
        
        return res;
    }
};