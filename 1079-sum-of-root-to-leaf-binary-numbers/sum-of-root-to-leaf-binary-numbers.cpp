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

    int sumRootToLeaf(TreeNode* root) {
        if (!root)
          return 0;

        stack<pair<TreeNode*, int>> st;

        int sum = 0;
        st.push({root, 0});

        while (!st.empty())
        {
            auto [node, cur] = st.top();
            st.pop();

            cur = cur << 1 | node->val;

            if (!node->left && !node->right)
            {
                sum += cur;
            }

            if (node->left)
              st.push({node->left, cur});
            if (node->right)
              st.push({node->right, cur});
        }

        return sum;
    }

};

/*
class Solution {
public:

    long long sum = 0;

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int path)
    {
       if (!root)
         return 0;
    
       path = path << 1 | root->val;
       
       if (!root->left && !root->right)
          return path;

      //父节点只是把左右子树的结果 加起来
      return dfs(root->left, path) + dfs(root->right, path);
       
    }
};
*/


/*
class Solution {
public:

    long long sum = 0;

    int sumRootToLeaf(TreeNode* root) {
        int path = 0;
        dfs(root, 0);

        return sum;
    }

    void dfs(TreeNode* root, int path)
    {
       if (!root)
         return;
    
       path = path << 1 | root->val;
       
       if (!root->left && !root->right)
       {
          sum += path;
       }

       dfs(root->left, path);
       dfs(root->right, path);
    }
};

*/