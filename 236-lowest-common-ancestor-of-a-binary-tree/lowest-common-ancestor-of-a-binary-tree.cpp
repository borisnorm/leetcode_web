/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
          return nullptr;
        
        //后根向上传递 p与 q 存在的信息 
        TreeNode* left  = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        //“我已经找到了 p（或 q），请祖先节点帮我判断，这是不是 LCA。”
        if (root == p || root == q)
          return root;

        // p and q are split here
        if (left && right) 
          return root;
        
        return left ? left : right;
    }
};