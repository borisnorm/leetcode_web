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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> nodes;
        
        dfs(root, 0,  0, nodes);

        using T = tuple<int, int, int>;
        auto cmp = [](const T& a, const T& b){
            if (get<0>(a) != get<0>(b))
               return get<0>(a) < get<0>(b);
            
            if (get<1>(a) != get<1>(b))
               return get<1>(a) < get<1>(b);
            
            return get<2>(a) < get<2>(b);
        };

        sort(nodes.begin(), nodes.end(), cmp);

        vector<vector<int>> res;
        int lastCol = INT_MIN;

        vector<int> colVal;
        for(auto& [col, row, val]: nodes)
        {
            if (lastCol != INT_MIN && col != lastCol)
            {
               res.push_back((colVal));
               colVal.clear();
            }

            colVal.push_back(val);

            lastCol = col;
        }

        if (!colVal.empty())
          res.push_back(colVal);

        return res;
    }

    void dfs(TreeNode* node, int row, int col, vector<tuple<int, int, int>>& nodes)
    {
        if (!node)
          return;
        
        nodes.emplace_back(col, row, node->val);

        dfs(node->left, row + 1, col - 1, nodes);
        dfs(node->right, row + 1, col + 1, nodes);
    }
};