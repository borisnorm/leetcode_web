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

 /*
class Solution {
public:
    double minDiff = INT_MAX * 1.0;
    int    minDiffNode = INT_MAX;
    int closestValue(TreeNode* root, double target) {
         minDiffNode = root ? root->val : 0; // é²ç©º
         dfs(root, target);

         return minDiffNode;
    }

    void dfs(TreeNode* root, double target)
    {
         if (!root)
           return;

         double diff = fabs(target - root->val);
         if (diff < minDiff)
         {
            minDiff = diff;
            minDiffNode = root->val; 
         }
         else if (diff == minDiff)
         {
            if (root->val < minDiffNode)
              minDiffNode = root->val;
         }
         
         if (root->left && root->val > target)
           dfs(root->left, target);
        
         if (root->right && root->val < target)
           dfs(root->right, target);
    }
};
*/