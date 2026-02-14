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

    
        return build(inorder, 0, n-1,
                     postorder, 0, n-1);
    }

    TreeNode* build(vector<int>& inorder, int inL, int inR,
                    vector<int>& postorder, int postL, int postR)
    {
       if (postL > postR)
         return nullptr;
        
       int rootval = postorder[postR];
       TreeNode* root = new TreeNode(rootval);

       //local inorder idx;
       int inIdx = val2idx[rootval];
       int leftSize = inIdx - inL;  // (inIdx - 1) - inL + 1


       // post-order
       //  left[L-root, L-left, L-right] right[R-root, R-left, R-right], root,
       // left [preStart + 1, preStart+leftsize]    |   right [preStart+leftSize+1, preEnd]
       root->left = build(inorder,   inL,   inIdx-1,
                          postorder, postL, postL + leftSize - 1);

       root->right = build(inorder, inIdx+1, inR,
                           postorder, postL + leftSize, postR-1);

       return root;
    }
};