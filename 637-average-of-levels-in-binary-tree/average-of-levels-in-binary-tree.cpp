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
    vector<double> averageOfLevels(TreeNode* root) {
        
        if (!root)
          return {};

        vector<double> res;
    
        queue<TreeNode*> node_queue;

        node_queue.push(root);

        while (!node_queue.empty())
        {
            int q_size = node_queue.size();
            int cnt = 0;
            double sum = 0;
            for (int i = 0; i < q_size; i++)
            {
                TreeNode* cur = node_queue.front();
                node_queue.pop();
                  
                sum += cur->val;
                cnt++;

                if (cur->left)
                  node_queue.push(cur->left);

                if (cur->right)
                  node_queue.push(cur->right);
            }

            double avg = sum/cnt;
            res.push_back(avg);
        }

        return res;
    }
};