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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
          return new TreeNode(val);
        
        TreeNode* cur = root;
        while(cur)
        {
           if (val < cur->val)
           {
              if (cur->left)
              {
                 cur = cur->left;
              }
              else
              {
                 cur->left = new TreeNode(val);
                 break;
              }
           }
           else
           {
              if (cur->right)
              {
                  cur = cur->right;
              }
              else
              {
                  cur->right = new TreeNode(val);
                  break;
              }
           }
        }

        return root;
    }
};

/*
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
          return new TreeNode(val);
        
        // 二分 , BST 是二分法
        if (val < root->val)
          root->left = insertIntoBST(root->left, val);
        else
          root->right = insertIntoBST(root->right, val);
    
        return root;
    }
};

*/

/*
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // 如果树为空，直接返回新节点
        if (!root) return new TreeNode(val);
        
        // 保存原始根节点用于最后返回
        TreeNode* cur = root;
        
        // 循环找到插入位置
        while (cur) {
            // 值小于当前节点，往左走
            if (val < cur->val) {
                // 如果左子节点为空，插入新节点
                if (!cur->left) {
                    cur->left = new TreeNode(val);
                    break;
                }
                cur = cur->left;
            } 
            // 值大于当前节点，往右走
            else {
                // 如果右子节点为空，插入新节点
                if (!cur->right) {
                    cur->right = new TreeNode(val);
                    break;
                }
                cur = cur->right;
            }
        }
        
        // 返回原始根节点
        return root;
    }
};
*/