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

    vector<int> rightSideView(TreeNode* root) {
        if (!root)
          return {};

         vector<int> res;
         dfs(root, 0, res);
         return res;
    };

    void dfs(TreeNode* root, int depth, vector<int>& res)
    {
        if (!root)
          return;
        
        if (depth == res.size())
          res.push_back(root->val);
        
        //right first
        dfs(root->right, depth+1, res);

        //left second
        dfs(root->left, depth+1, res);
    }
};


/*
class Solution {
public:
    vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
          return {};

         dfs(root, 0);
         return res;
    };

    void dfs(TreeNode* root, int depth)
    {
        if (!root)
          return;
        
        if (depth == res.size())
          res.push_back(root->val);
        
        // right first
        dfs(root->right, depth+1);
        dfs(root->left, depth+1);
    }
};
*/
/*
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
         vector<int> res;
         if (!root)
           return res;

         queue<TreeNode*> nodes_queue;
         nodes_queue.push(root);


         while (!nodes_queue.empty())
         {
            int queue_size = nodes_queue.size();
            vector<int> level;
            for (int i = 0; i < queue_size; i++)
            {
                TreeNode* node = nodes_queue.front();
                nodes_queue.pop();

                level.push_back(node->val);

                if (node->left)
                  nodes_queue.push(node->left);
                if (node->right)
                  nodes_queue.push(node->right);
            }

            res.push_back(level.back());
         }

         return res;
    }
};

*/