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
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root)
    {
        if (!root)
          return -1;
        
        int leftH = dfs(root->left);
        int rightH = dfs(root->right);

        int height = max(leftH, rightH) + 1;

        if (res.size() <= height)
            res.push_back({});
        
        res[height].push_back(root->val);

        return height;
    }

};