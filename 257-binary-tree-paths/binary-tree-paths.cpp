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

    vector<string> binaryTreePaths(TreeNode* root)
    {
        if (!root)
          return {};

        stack<pair<TreeNode*, string>> st;
        string path;
        vector<string> res;
        
        st.push({root, path});
        while (!st.empty())
        {
           auto [node, path] = st.top();
           st.pop();

           if (!path.empty())
             path += "->";
           path += to_string(node->val);

           if (!node->left && !node->right)
           {
             res.push_back(path);
           }

           if (node->right)
             st.push({node->right, path});

           if (node->left)
             st.push({node->left, path});
        }

        return res;
    }

/*
    vector<string> binaryTreePaths(TreeNode* root) {
         if (!root)
           return {};
         vector<string> res;
         string path;

         binaryTreeTraverse(root, path, res);

         return res;
    }

    void binaryTreeTraverse(TreeNode* root, string str, vector<string>& res)
    {
        if (!root)
          return;

        if (!str.empty())
          str += "->";

        str += to_string(root->val);
     
        if (!root->left && !root->right)
        {
           res.push_back(str);
           return;
        }

        if(root->left) 
          binaryTreeTraverse(root->left, str, res);
        if (root->right)
          binaryTreeTraverse(root->right, str, res);
    } 

    */


};