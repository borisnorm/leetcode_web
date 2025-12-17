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
    unordered_map<int, vector<TreeNode*>> memo;
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n%2 == 0)
          return  {};

        if (memo.count(n))
          return memo[n];
        
        vector<TreeNode*> res;

        if (n == 1)
        {
           res.push_back(new TreeNode(0));
           memo[n] = res;
           return res;
        }

        for (int i = 1; i <= n-2; i+=2)
        {
           int j = (n-1) - i;

           auto leftTrees = allPossibleFBT(i);
           auto rightTrees = allPossibleFBT(j);

           for (auto* L : leftTrees)
             for (auto* R: rightTrees)
             {
                TreeNode* root = new TreeNode(0);
                root->left = L;
                root->right = R;
                res.push_back(root);
             }
        }

        memo[n] = res;
        return res;
    }
};