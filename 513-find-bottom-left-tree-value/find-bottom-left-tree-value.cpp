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
    int findBottomLeftValue(TreeNode* root) {
        if (!root)
          return 0;

        queue<TreeNode*> q;
        q.push(root);

        int res = root->val;

        while (!q.empty())
        {
           int q_sz = q.size();

           res = q.front()->val;
           for (int i = 0; i < q_sz; i++)
           {
              TreeNode* cur = q.front();
              q.pop();

              if (cur->left)
                q.push(cur->left);

              if (cur->right)
                q.push(cur->right);
           }

        }

        return res;
    }

};

/*
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (!root)
          return 0;
        queue<TreeNode*> q;
        q.push(root);


        int res = 0;
        
        int maxDepth = nodeMaxDepth(root);
        int level = 0;
        while (!q.empty())
        {
           int q_sz = q.size();
           for (int i = 0; i < q_sz; i++)
           {
              TreeNode* cur = q.front();
              q.pop();

              if (level + 1 == maxDepth)
              {
                  res = cur->val;
                  return res;
              }

              if (cur->left)
                q.push(cur->left);

              if (cur->right)
                q.push(cur->right);
           }

           level++;
        }

        return res;
    }

    int nodeMaxDepth(TreeNode* node)
    {
        if (!node)
          return 0;

        return max(nodeMaxDepth(node->left), nodeMaxDepth(node->right)) + 1;
    }
};

*/