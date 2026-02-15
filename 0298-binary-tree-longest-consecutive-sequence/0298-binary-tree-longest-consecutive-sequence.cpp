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
    int longestConsecutive(TreeNode* root) {
        if (!root)
          return 0;
        int maxLen = 0;
        dfs(root, nullptr, 0, maxLen);
        return maxLen;
    }

    void dfs(TreeNode* root, TreeNode* parent, int curLen, int& maxLen)
    {
        if (!root)
          return;
        if (parent && root->val == parent->val + 1)
          curLen++;
        else
          curLen = 1;
        
        maxLen = max(maxLen, curLen);

        dfs(root->left, root, curLen, maxLen);
        dfs(root->right, root, curLen, maxLen);
    }

};