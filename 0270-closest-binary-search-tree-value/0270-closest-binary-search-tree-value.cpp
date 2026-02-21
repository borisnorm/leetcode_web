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
    int closestValue(TreeNode* root, double target) {
         if (!root)
            return -1;    

         int minVal = INT_MAX;
         dfs(root, target, minVal);   
         return minVal;    
    }

    void dfs(TreeNode* root, double target, int& minVal)
    {
        if (!root)
          return;
        
        if (fabs(root->val - target) < fabs(minVal - target))
          minVal = root->val;
        else if (fabs(root->val - target) == fabs(minVal - target))
          minVal = min(root->val, minVal);
        
       dfs(root->left, target, minVal);
       dfs(root->right, target, minVal);        
    }
};