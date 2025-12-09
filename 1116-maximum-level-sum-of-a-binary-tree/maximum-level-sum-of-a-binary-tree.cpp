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
    int maxLevelSum(TreeNode* root) {
        
        if (!root)
          return 0;

        queue<TreeNode*> tree_q;
        tree_q.push(root);

        int   maxLevel = 1;
        int   maxSum = INT_MIN; 

        int level = 1;
        while (!tree_q.empty())
        {
            int sum = 0;
            int q_size = tree_q.size();
            for (int i = 0; i < q_size; i++)
            {
               TreeNode* cur = tree_q.front();
               tree_q.pop();
           
               sum += cur->val;

               if (cur->left)
                 tree_q.push(cur->left);
                
               if (cur->right)
                 tree_q.push(cur->right);
            }

            if (sum > maxSum)
            {
                maxSum = sum;
                maxLevel = level;
            }
            level++;
        }

        return maxLevel;
    }
};