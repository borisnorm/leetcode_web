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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.empty() || postorder.empty())
          return nullptr;
        int n = postorder.size();

        for (int i = 0; i < n; i ++)
          val2idx[postorder[i]] = i;
        
        return build(preorder, 0, n-1, postorder, 0, n-1);
    }

    TreeNode* build(vector<int>& preorder, int preL, int preR, vector<int>& postorder, int postL, int postR)
    {
        if (postL > postR)
          return nullptr;
        
        int rootval = preorder[preL++];
        TreeNode* root = new TreeNode(rootval);

        if (postL == postR)
          return root;

        int leftRootVal = preorder[preL];
        int postIdx = val2idx[leftRootVal];
        int leftSize = postIdx - postL + 1;

        root->left = build(preorder, preL, preL + leftSize - 1, 
                          postorder, postL, postIdx);
        root->right = build(preorder,preL + leftSize, preR,
                        postorder, postIdx+1, postR-1);
        return root;

    }
};


/*
class Solution {
public:
    unordered_map<int, int> val2idx;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.empty() || postorder.empty())
          return nullptr;

        // 1 [2 4 5] [3 6 7]
        // [4 5 2] [6 7 3] 1
        // preIdx++
        
        // find root
        // find left range, right range
        int m = preorder.size();
        int n = postorder.size();
        for(int i = 0; i < n; i++)
          val2idx[postorder[i]] = i;

        int preIdx = 0;
        return build(preorder, preIdx, postorder, 0, n-1);
    }

    TreeNode* build(vector<int>& preorder, int& preIdx, 
                    vector<int>& postorder, int postL, int postR)
    {
        if (postL > postR)
            return nullptr;

        int rootval = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootval);

        if (postL == postR)
          return root;
        
        int leftRootVal = preorder[preIdx];
        int postIdx = val2idx[leftRootVal];

        root->left = build(preorder, preIdx,
                          postorder, postL, postIdx);
        root->right = build(preorder, preIdx,
                          postorder, postIdx+1, postR-1);
        return root;
    }
};
*/