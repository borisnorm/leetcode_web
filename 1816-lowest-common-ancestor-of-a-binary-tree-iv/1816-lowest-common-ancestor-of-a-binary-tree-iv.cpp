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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
          if (!root)
            return nullptr;
          unordered_set<TreeNode*> node_set(nodes.begin(), nodes.end());

          return findLCA(root, node_set);
    }

    TreeNode* findLCA(TreeNode* root, unordered_set<TreeNode*>& node_set)
    {
        if (!root)
          return nullptr;
        
        TreeNode* left = findLCA(root->left, node_set);
        TreeNode* right = findLCA(root->right, node_set);

        if (node_set.count(root))
          return root;
        
        if (left && right)
          return root;
        
        return left ? left : right;
    }
};