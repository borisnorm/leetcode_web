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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)
          return {};

        vector<int> path;
        dfs(root, targetSum, path);
        return res;        
    }

    void dfs(TreeNode* root, int targetSum, vector<int>& path)
    {
        if (!root)
          return;

        targetSum = targetSum - root->val;

        path.push_back(root->val);

        if (!root->left && !root->right && targetSum == 0)
        {
           res.push_back(path);
        }
        //else
        {
          dfs(root->left, targetSum, path);
          dfs(root->right, targetSum, path);
        }

        path.pop_back();
    }
};