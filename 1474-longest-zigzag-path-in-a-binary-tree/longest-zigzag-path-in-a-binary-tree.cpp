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
    int ans = 0;

    int longestZigZag(TreeNode* root) {
        if (!root )
          return -1;

        pathlen(root->left, true, 1);
        pathlen(root->right, false, 1);

        return ans;
    }

    void pathlen(TreeNode* root, bool isLeft, int len)
    {
        if (!root)
          return;

        ans = max(ans, len);

        if (isLeft)
        {
           if (root->right)
             pathlen(root->right, false, len + 1);
            
           if (root->left)
             pathlen(root->left, true, 1);
        }
        else
        {
           if (root->left)
             pathlen(root->left, true, len + 1);
           
           if (root->right)
             pathlen(root->right, false, 1);

        }
    }
 
};