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
    // key (l, r) -> all BST roots built from [l..r]
    map<pair<int, int>, vector<TreeNode*>> memo;
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
          return {};
        
        memo.clear();

        return build(1, n);
    }

    vector<TreeNode*> build(int l, int r)
    {
        if (l > r)
          return {nullptr};
        
        auto key = make_pair(l, r);

        if (memo.count(key))
          return memo[key];

        vector<TreeNode*> res;

        for (int root = l; root <= r; root++)
        {
            vector<TreeNode*> leftTrees = build(l, root - 1);
            vector<TreeNode*> rightTrees = build(root + 1, r);

            for (TreeNode* L : leftTrees)
            {
                for (TreeNode* R : rightTrees)
                {
                    TreeNode* cur = new TreeNode(root);
                    cur->left = L;
                    cur->right = R;
                    res.push_back(cur);
                }
            }
        }

        /* update memo */
        memo[key] = res;

        return res;

    }

};