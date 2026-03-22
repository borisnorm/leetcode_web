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
    
    int res;
    int countPairs(TreeNode* root, int distance) {
        if (!root)
          return 0;
        
        dfs(root, distance);
        return res;
    }

    vector<int> dfs(TreeNode* node, int dist)
    {
       if (!node)
         return {};
       
       if (!node->left && !node->right)
         return {1};
      
       auto L = dfs(node->left, dist);
       auto R = dfs(node->right, dist);

       for (int l: L)
       {
         for (int r: R)
         {
            if (l + r <= dist)
              res++;
         }
       }

       vector<int> cur_dist;
       for (int l: L)
       {
         if (l+1 <= dist)
           cur_dist.push_back(l+1);
       }

       for (int r: R)
       {
          if (r+1 <= dist)
            cur_dist.push_back(r+1);
       }
       return cur_dist;
    }
};