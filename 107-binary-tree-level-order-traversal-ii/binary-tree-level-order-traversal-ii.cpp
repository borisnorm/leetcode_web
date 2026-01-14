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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)
          return {};
        
        vector<vector<int>> res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int q_sz = q.size();
            vector<int> level;

            for (int i = 0; i < q_sz; i++)
            {
                TreeNode* cur = q.front();
                q.pop();

                level.push_back(cur->val);

                if (cur->left)
                  q.push(cur->left);
                if (cur->right)
                  q.push(cur->right);
            }

            res.insert(res.begin(), level);
        }

        return res;
    }
};