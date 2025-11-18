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

    int minVal = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        if (!root)
          return 0;
        
        getMinimumDifference(root->left);
        getMinimumDifference(root->right);
        caldiff(root->left, root->val);
        caldiff(root->right, root->val);

        return minVal;
    }
   
    void caldiff(TreeNode* root, int target)
    {
        if (!root)
          return ;

        minVal = min(minVal, abs(target-root->val));

        caldiff(root->left, target);
        caldiff(root->right, target);
    }

};