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
    pair<int, TreeNode*> infoX;
    pair<int, TreeNode*> infoY;
    bool isCousins(TreeNode* root, int x, int y) {
       if (!root || x == y)
         return false;
       
       dfs(root, nullptr, 0, x, y);

       if (infoX.first == infoY.first && 
           infoX.second != infoY.second)
         return true;
      
       return false;
    }
   
    // same depth, with different parent;
    void dfs(TreeNode* root, TreeNode* par, int depth, int x, int y)
    {
       if (!root)
         return;
       
       if (root->val == x)
         infoX = {depth, par};
       if (root->val == y)
         infoY = {depth, par};

        dfs(root->left, root, depth+1, x, y);
        dfs(root->right, root, depth+1, x, y);
    }
};