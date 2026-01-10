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

    long long sum = 0;

    int sumRootToLeaf(TreeNode* root) {
        int path = 0;
        dfs(root, 0);

        return sum;
    }

    void dfs(TreeNode* root, int path)
    {
       if (!root)
         return;
    
       path = path << 1 | root->val;
       
       if (!root->left && !root->right)
       {
          sum += path;
       }

       dfs(root->left, path);
       dfs(root->right, path);
    }
};