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
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
          return nullptr;
        
        swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

 /*

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      queue<TreeNode*> nodes_queue;
      
      if (!root)
        return root;

      nodes_queue.push(root);

      while(!nodes_queue.empty())
      {
        int queue_size = nodes_queue.size();
        for (int i = 0; i < queue_size; i++)
        {
           TreeNode* node = nodes_queue.front();
           nodes_queue.pop();

           TreeNode* left  = node->left;
           TreeNode* right = node->right;

           node->left  = right;
           node->right = left;
           
           if (node->left)
             nodes_queue.push(node->left);

           if (node->right)
             nodes_queue.push(node->right);                
        }
      }

      return root;
    }
};

*/