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
        if (preorder.empty() || inorder.empty())
          return nullptr;
        int n = inorder.size();
        // inorder 的作用是什么 
        // left -> root -> right
        for (int i = 0; i < inorder.size(); i++)
          val2idx[inorder[i]] = i;
        
        // 包含当前 root,的 pre-order[start, end]  以及 in-order[start, end]
        return build(preorder, 0, n-1, inorder, 0, n-1);
    }

    TreeNode* build(vector<int>& preorder, int preL, int preR, 
                    vector<int>& inorder, int inL, int inR)
    {
       // check preorder availbility 因为 root 从它这里来
       if (preL > preR)
         return nullptr;

       // get root from pre-order
       int rootval = preorder[preL];
       TreeNode* root = new TreeNode(rootval);
       
       // get inorder pivot idx from root->idx map 
       int inIdx = val2idx[rootval];
       int leftSize = inIdx - inL;  // get left size of inorder, meantime it is the size of left child for pre-order
    
       //
       // pre-order
       // root, left[L-root, L-left, L-right] right[R-root, R-left, R-right]
       // left [preStart + 1, preStart+leftsize]    |   right [preStart+leftSize+1, preEnd]
       // (preSart + leftSize) - (preStart + 1) + 1 = leftsize
       // end = start + len - 1
       root->left = build(preorder, preL + 1, preL + leftSize,  
                          inorder,  inL, inIdx-1);
     
       // inorder
       // left[L-left, L-root, L-right], root, right[R-left, R-root, R-right]
       // left [inorder_start, idx-1]   [idx+1, inorder_end]
       root->right = build(preorder, preL + leftSize + 1, preR,
                           inorder, inIdx + 1, inR);
       return root;
    }
};