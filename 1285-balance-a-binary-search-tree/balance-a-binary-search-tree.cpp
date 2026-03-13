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
    TreeNode* balanceBST(TreeNode* root) {
        if (!root)
          return root;

        vector<int> vals;
        inorder(root, vals);
        int n = vals.size();
        return build(vals, 0, n-1);
    }

    void inorder(TreeNode* root,  vector<int>& vals)
    {
        if (!root)
          return;
        
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

    TreeNode* build(vector<int>& vals, int l, int r)
    {
       if (l > r)
         return nullptr;
      
       int mid = l + (r-l)/2;
       TreeNode* root = new TreeNode(vals[mid]);

       root->left  = build(vals, l, mid-1);
       root->right = build(vals, mid+1, r);

       return root;
    }
};