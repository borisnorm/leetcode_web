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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)
          return {};

        vector<int> path;
        dfs(root, targetSum, path);
        return res;        
    }

    void dfs(TreeNode* root, int targetSum, vector<int>& path)
    {
        if (!root)
          return;

        //targetSum = targetSum - root->val;
        path.push_back(root->val);

        if (!root->left && !root->right && targetSum == root->val)
        {
           //如果是 leaf 节点, 那么 再次调用 dfs(root->left) 活儿 dfs(root->right) 他们都会返回 null 是
           res.push_back(path);
           // 没有 return 是因为要 path.pop_back();, 不然会污染路径的
        }
 
        dfs(root->left, targetSum-root->val, path);
        dfs(root->right, targetSum-root->val, path);

        path.pop_back();
    }
};

/*
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)
          return {};

        vector<int> path;
        vector<vector<int>> res;

        stack<tuple<TreeNode*, int, vector<int>>> st;
        st.push({root, targetSum, path});


         //TreeNode* cur = root;
        while(!st.empty())
        {
          auto [cur, target, path] = st.top();
          st.pop();

          target = target - cur->val;
          path.push_back(cur->val);
          if (!cur->left && !cur->right && target == 0)
          {
             res.push_back(path);
          }

          if (cur->right)
            st.push({cur->right, target, path});
        
          if (cur->left)
            st.push({cur->left, target, path});
        
        }

        return res;
    }
};

*/