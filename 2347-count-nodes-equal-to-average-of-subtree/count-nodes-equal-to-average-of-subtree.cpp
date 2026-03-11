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
    int averageOfSubtree(TreeNode* root) {
        
        //root-?
        //post order
        if (!root)
          return 0;
        
        postOrder(root);
        return res;
    }

    int res = 0;
    pair<int, int> postOrder(TreeNode* root)
    {
        if (!root)
          return {0, 0};
        
        auto [lsum, lcnt] = postOrder(root->left);
        auto [rsum, rcnt] = postOrder(root->right);

        int sum = lsum + rsum + root->val;
        int cnt = lcnt + rcnt + 1;

        if (sum/cnt == root->val)
          res++;

        return {sum, cnt};
    }
};