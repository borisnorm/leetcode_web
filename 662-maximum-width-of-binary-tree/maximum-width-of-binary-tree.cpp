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
    int widthOfBinaryTree(TreeNode* root) {
         if (!root)
          return 0;

         queue<pair<TreeNode*, long long>> node_queue;
         node_queue.push(make_pair(root, 0));

         int ans = 0;

         while (!node_queue.empty())
         {
           int queue_size = node_queue.size();
           pair<TreeNode*, int> top_node = node_queue.front();
           long long base = top_node.second;
           long long left = 0;
           long long right = 0;

           for (int i = 0; i < queue_size; i++)
           {
              pair<TreeNode*, long long> node_pair = node_queue.front();
              node_queue.pop();

              TreeNode* node = node_pair.first;
              long long cur = node_pair.second - base;

              if (i == 0)
                left = cur;
            
              if (i == queue_size - 1)
                right = cur;
               
              if (node->left)
                node_queue.push(make_pair(node->left, 2*cur+1));

              if (node->right)
                node_queue.push(make_pair(node->right, 2*cur+2));
           }

           int width = right - left + 1;
           ans = max (ans, width);

         }
 
         return ans;
    }
};