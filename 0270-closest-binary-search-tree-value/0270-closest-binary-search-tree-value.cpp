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
    int closestValue(TreeNode* root, double target) {
        
          TreeNode* cur = root;
          int closestNodeVal = root->val;

          while(cur)
          {
              
              double diff1 = abs(cur->val - target);
              double diff2 = abs(closestNodeVal - target);
              if (diff1 < diff2 || ((diff1 == diff2) && cur->val < closestNodeVal))
              {
                  closestNodeVal = cur->val;
              }

              if (cur->val > target)
                cur = cur->left;
              else
                cur = cur->right;
          }

          return closestNodeVal;
    }
};