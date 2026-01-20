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

 TreeNode* removeLeafNodes(TreeNode* root, int target) {

      if (!root)
        return root;

      return dfs(root, target);
 }

 TreeNode* dfs(TreeNode* root, int target)
 {
    if (!root)
      return nullptr;
    
    root->left = dfs(root->left, target);
    root->right = dfs(root->right, target);

    if (!root->left && !root->right && root->val == target)
      return nullptr;

    return root;
 }

/*
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root)
          return root;

        if(dfs(root, target))
          return nullptr;

        return root;
    }


   
    bool dfs(TreeNode* root, int target)
    {
       if (!root)
         return false;
        
       if (dfs(root->left, target))
         root->left = nullptr;

       if (dfs(root->right, target))
         root->right = nullptr;
    
       if (!root->left && !root->right && root->val == target)
          return true;

       return false;
    }

*/
};