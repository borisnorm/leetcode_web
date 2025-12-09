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

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> root1_leaf;
        vector<int> root2_leaf;  
        
        dfs(root1, root1_leaf);
        dfs(root2, root2_leaf);

        return root1_leaf == root2_leaf;
    }

    void dfs(TreeNode* root, vector<int>& leaf)
    {
       if (!root)
         return;
       
       dfs(root->left, leaf);

       if (!root->left && !root->right)
          leaf.push_back(root->val);

       dfs(root->right, leaf);
    }
};