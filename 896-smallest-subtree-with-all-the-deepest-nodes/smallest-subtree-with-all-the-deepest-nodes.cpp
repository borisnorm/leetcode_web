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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root)
          return root;
        
        auto [subtreeParent, depth] = dfs(root, nullptr);
        return subtreeParent;
    }

    pair<TreeNode*, int> dfs(TreeNode* root, TreeNode* parent)
    {
        if (!root)
          return {nullptr, 0};

        int l_depth = 0;
        int r_depth = 0;
        TreeNode* leftSubtreeParent = nullptr;
        TreeNode* rightSubtreeParent = nullptr;
        if (root->left)
        {
          auto res  = dfs(root->left, parent);
          leftSubtreeParent = res.first;
          l_depth = res.second;
        }
        
        if (root->right)
        {
          auto res = dfs(root->right, parent);
          rightSubtreeParent = res.first;
          r_depth = res.second;
        }

        TreeNode* subtreeParent = nullptr;
        int maxDepth = 0;
        if (l_depth == r_depth)
        {
          maxDepth = l_depth;
          subtreeParent = root;
        }
        else if (l_depth > r_depth)
        {
           maxDepth = l_depth;
           subtreeParent = leftSubtreeParent;
        }
        else
        {
           maxDepth = r_depth;
           subtreeParent = rightSubtreeParent;
        }

        return {subtreeParent, maxDepth + 1};
    }
};