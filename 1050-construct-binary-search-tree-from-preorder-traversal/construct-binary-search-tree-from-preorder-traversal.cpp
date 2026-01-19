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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return dfs(preorder, i, INT_MAX);

    }

    TreeNode* dfs(vector<int>& preorder, int& i, int bound)
    {

       int n = preorder.size();
       if (i >= n)
         return nullptr;
    
       int val = preorder[i];

       if (val > bound)
         return nullptr;
       TreeNode* node = new TreeNode(val);  // 构建的时候初始下面为 nullptr;

       i++;

       node->left = dfs(preorder, i, val);

       node->right = dfs(preorder, i, bound);

       return node;
    }
};