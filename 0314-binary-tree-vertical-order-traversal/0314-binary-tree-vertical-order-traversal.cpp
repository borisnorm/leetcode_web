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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root)
          return {};

        // col id -> col values
        unordered_map<int, vector<int>> col2vals;

        // node, col id
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        int minCol = 0;
        int maxCol = 0;
        while(!q.empty())
        {
            auto [cur, col] = q.front();
            q.pop();

            col2vals[col].push_back(cur->val);
            minCol = min(minCol, col);
            maxCol = max(maxCol, col);
            
            if (cur->left)
              q.push({cur->left, col-1});
            
            if (cur->right)
              q.push({cur->right, col+1});
        }
        
        vector<vector<int>> res;
        for (int i = minCol; i <= maxCol; i++)
        {
           res.push_back(move(col2vals[i]));
        }

        return res;
    }
};