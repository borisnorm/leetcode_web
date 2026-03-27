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
    long long total = 0;
    long long best = 0;
    long long MOD = 1e9+7;
    long long dfs(TreeNode* root)
    {
      if (!root)
        return 0;
      
      long long left = dfs(root->left);
      long long right = dfs(root->right); 

      long long subSum = root->val + left + right;
      
      best = max(best, subSum * (total - subSum));

      return subSum;
    }
    int maxProduct(TreeNode* root) {
        
        total = dfs(root);

        best = 0;
        dfs(root);

        return best % MOD;
        
    }
};