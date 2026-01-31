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

   int minDepth(TreeNode* root)
   {
       if (!root)
         return 0;
        
       if (!root->left && !root->right)
         return 1;

       if (!root->left)
         return minDepth(root->right) + 1;
        
       if (!root->right)
         return minDepth(root->left) + 1;

       int leftDepth  = minDepth(root->left);
       int rightDepth = minDepth(root->right);

       return min(leftDepth, rightDepth) + 1;
   }

 /*
    int minDepth(TreeNode* root) {
        if (!root)
          return 0;

        if (!root->left && !root->right)
          return 1;

        int minLeft  = (root->left) ? minDepth(root->left) : INT_MAX;
        int minRight = (root->right) ? minDepth(root->right) : INT_MAX; 

        return min(minLeft, minRight) + 1; 
    }
    */
};

/*
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1}); // 节点 + 当前深度

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            // 叶子节点，直接返回
            if (!node->left && !node->right) {
                return depth;
            }

            if (node->left)  q.push({node->left,  depth + 1});
            if (node->right) q.push({node->right, depth + 1});
        }

        return 0; // 理论上不会走到这里
    }
};
*/