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
    int res = 0; // 全局计数摄像头数量

    // 返回状态: 0=需要覆盖, 
    //          1=有摄像头, 
    //          2=已覆盖
    int dfs(TreeNode* node) {

        if (!node) 
           return 2; // null节点视为已覆盖，避免在叶子的父节点多装摄像头

        int l = dfs(node->left);  // 后序：先处理左子树
        int r = dfs(node->right); // 后序：先处理右子树

        if (l == 0 || r == 0) 
        { // 任一子节点需要覆盖 → 当前装摄像头
            res++;
            return 1;
        }
        else if (l == 1 || r == 1) 
        { // 任一子节点有摄像头 → 当前已被覆盖
            return 2;
        }

        return 0; // 两个子节点都是已覆盖状态 → 当前节点自己没被覆盖，返回给父节点处理
    }

    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) 
          res++; // 根节点还没覆盖，额外加一个摄像头
        return res;
    }
};