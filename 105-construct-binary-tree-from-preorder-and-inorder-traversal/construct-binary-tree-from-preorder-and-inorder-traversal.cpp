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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // inorder 的作用是什么 
        // left -> root -> right
        for (int i = 0; i < inorder.size(); i++)
          val2idx[inorder[i]] = i;
        
        // 包含当前 root,的 pre-order[start, end]  以及 in-order[start, end]
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, 
                    vector<int>& inorder, int inStart, int inEnd)
    {
       // check preorder availbility 因为 root 从它这里来
       if (preStart > preEnd)
         return nullptr;

       // get root from pre-order
       int rootval = preorder[preStart];
       
       // get inorder pivot idx from root->idx map 
       int in_idx = val2idx[rootval];
       int leftSize = in_idx - inStart;  // get left size of inorder, meantime it is the size of left child for pre-order
    
       TreeNode* root = new TreeNode(rootval);
       //
       // pre-order
       // root, left[L-root, L-left, L-right] right[R-root, R-left, R-right]
       // left [preStart + 1, preStart+leftsize]    |   right [preStart+leftSize+1, preEnd]
       root->left = build(preorder, preStart+1, preStart + leftSize,
                          inorder,  inStart, in_idx-1);
     
       // inorder
       // left[L-left, L-root, L-right], root, right[R-left, R-root, R-right]
       // left [inorder_start, idx-1]   [idx+1, inorder_end]
       root->right = build(preorder, preStart + leftSize + 1, preEnd,
                           inorder, in_idx + 1, inEnd);
       return root;
    }
};