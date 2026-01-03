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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
          if (!root1 && !root2)
            return nullptr;
          
          int val = (root1 ? root1->val : 0) + 
                    (root2 ? root2->val : 0);
          TreeNode* root = new TreeNode(val);

          queue<tuple<TreeNode*, TreeNode*, TreeNode*>> q;
          q.push({root, root1, root2});

          while (!q.empty())
          {
             auto [n, n1, n2] = q.front();
             q.pop();
             
             TreeNode* l1 = n1 ? n1->left : nullptr;
             TreeNode* l2 = n2 ? n2->left : nullptr;

             if (l1 || l2)
             {
                int val = (l1 ? l1->val : 0) + (l2 ? l2->val: 0);
                n->left = new TreeNode(val);
                q.push({n->left, l1, l2});
             }

             TreeNode* r1 = n1 ? n1->right : nullptr;
             TreeNode* r2 = n2 ? n2->right : nullptr;

             if (r1 || r2)
             {
                int val = (r1 ? r1->val : 0) + (r2 ? r2->val : 0);
                n->right = new TreeNode(val);
                q.push({n->right, r1, r2});
             }
          }

          return root;
    }
};

/*

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1)
          return root2;
        if (!root2)
          return root1;
        
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root1, root2});

        while (!q.empty())
        {
           auto [n1, n2] = q.front();
           q.pop();
           
           n1->val += n2->val;

           if (n1->left && n2->left)
           {
              q.push({n1->left, n2->left});
           }
           else if (!n1->left)
           {
              n1->left = n2->left;
           }

           if (n1->right && n2->right)
           {
              q.push({n1->right, n2->right});
           }
           else if (!n1->right)
           {
               n1->right = n2->right;
           }
        }

        return root1;
    }
};

*/

/*
// 正确
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1)
          return root2;
        if (!root2)
          return root1;
        
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};

*/

/*
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
          if (!root1 && !root2)
            return nullptr;
          
          int val = (root1 ? root1->val : 0) +
                    (root2 ? root2->val : 0);
          TreeNode* root = new TreeNode(val);

          root->left = mergeTrees(root1 ? root1->left: nullptr, 
                                  root2 ? root2->left: nullptr);
          root->right = mergeTrees(root1 ? root1->right: nullptr, 
                                   root2 ? root2->right: nullptr);
           
          return root;
    }
};
*/
