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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
          return nullptr;

        if (key < root->val)
          root->left  = deleteNode(root->left, key);
        else if (key > root->val)
          root->right = deleteNode(root->right, key);
        else
        {
           if (!root->left && !root->right)
           {
              delete root;
              return nullptr;
           }

           if (!root->left)
           {
             // 返回后 让 父节点指向 avail 的子节点, 绕过当前节点 达到删除目的
             TreeNode* right = root->right;
             delete root;
             return right;
           }
           
           if (!root->right)
           {
             TreeNode* left = root->left;
             delete root;
             return left;
           }
        
           // 找右子树最小节点
           TreeNode* minNode = getmin(root->right);
           
           // 用最小节点值替换当前节点
           root->val = minNode->val;
           // 删除右子树中该最小节点
           root->right = deleteNode(root->right, minNode->val);
        }

       return root;
    }

    TreeNode* getmin(TreeNode* node)
    {
        while (node->left)
          node = node->left;

        return node;
    }
};