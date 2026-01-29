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
    int rob(TreeNode* root) {
        auto res = dfs(root); // 获取根节点的{不抢, 抢}结果
        return max(res.first, res.second); // 返回两种情况的最大值
    }
    
    // 返回{不抢当前节点的最大值, 抢当前节点的最大值}
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0}; // 空节点，两种情况都是0
        
        auto l = dfs(node->left);  // 递归左子树，得到{不抢左孩子, 抢左孩子}
        auto r = dfs(node->right); // 递归右子树，得到{不抢右孩子, 抢右孩子}
        
        // 不抢当前节点：左右子节点都可以选择抢或不抢，取最大
        int notRob = max(l.first, l.second) + max(r.first, r.second);
        
        // 抢当前节点：必须不抢左右子节点，加上当前节点的值
        int rob = node->val + l.first + r.first;
        
        return {notRob, rob}; // 返回当前节点的两种情况
    }
};