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
    TreeNode* str2tree(string s) {
        intÂ i = 0;
        return dfs(s, i);
    }

    TreeNode* dfs(string s, int& i)
    {
       int n = s.size();
       if (i >= n)
         return nullptr;
    
       int sign = 1;
       if (s[i] == '-')
       {
          sign = -1;
          i++;
       }

       int val = 0;
       while (i < n && isdigit(s[i]))
       {
          val = val* 10 + (s[i] - '0');
          i++;
       }

       TreeNode* root = new TreeNode(sign * val);

       if (i < n && s[i] == '(')
       {
           i++; // jump over the first '('
           root->left = dfs(s, i);
           i++;  // jump over the last ')'
       }

       if (i < n && s[i] == '(')
       {
          i++;
          root->right = dfs(s, i);
          i++;
       }

       return root;
    }
};