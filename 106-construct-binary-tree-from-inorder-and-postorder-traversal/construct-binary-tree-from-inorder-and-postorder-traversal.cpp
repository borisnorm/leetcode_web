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
    unordered_map<int, int> val2idx;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
          val2idx[inorder[i]] = i;

        return _buildTree(inorder, 0, inorder.size()-1,
                          postorder, 0, postorder.size()-1);
    }

    TreeNode* _buildTree(vector<int>& inorder, int inOrder_start, int inOrder_end,
                         vector<int>& postorder, int postOrder_start, int postOrder_end)
    {
       if (postOrder_start > postOrder_end)
         return nullptr;
        
       int rootval = postorder[postOrder_end];

       //local inorder idx;
       int inOrder_idx = val2idx[rootval];
       int leftsize = inOrder_idx - inOrder_start;  // len of left set of post order and in order

       TreeNode* root = new TreeNode(rootval);
       // post-order
       //  left[L-root, L-left, L-right] right[R-root, R-left, R-right], root,
       // left [preStart + 1, preStart+leftsize]    |   right [preStart+leftSize+1, preEnd]
       root->left = _buildTree(inorder,   inOrder_start,   inOrder_idx-1,
                               postorder, postOrder_start, postOrder_start + leftsize - 1);

       root->right = _buildTree(inorder, inOrder_idx+1, inOrder_end,
                            postorder, postOrder_start + leftsize, postOrder_end - 1);

       return root;
    }
};