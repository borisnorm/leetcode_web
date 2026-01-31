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
    int getLeftDepth(TreeNode* root)
    {
       //if (!root)
       //   return 0;
          
        int level = 0;
        while (root)           // root本身就是第一层
        { 
          level++;             // 所以这里会先++，把root算进去
          root = root->left;
        } 
       return level;
    }

    int getRightDepth(TreeNode* root)
    {
       // if (!root)
       //   return 0;

        int level = 0;
        while (root)
        {
           level++;
           root = root->right;
        }

        return level;
    }

    int countNodes(TreeNode* root) {
        if (!root)
          return 0;

        int leftDepth  = getLeftDepth(root);   // 从当前节点往左边界走的深度
        int rightDepth = getRightDepth(root);  // 从当前节点往右边界走的深度

        if (leftDepth == rightDepth)
        {
           //是的！2^h - 1 算的是包含root在内的满二叉树节点总数
           int cnt = (1 << leftDepth) - 1;
           return cnt;
        }  

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};