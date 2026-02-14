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
        if (preorder.empty())
          return nullptr;
        
        int preIdx = 0;
        return build(preorder, preIdx, INT_MIN, INT_MAX);
    }

    TreeNode* build(vector<int>& preorder, int& preIdx, long long low, long long high)
    {
       int n = preorder.size();
       if (preIdx >= n)
         return nullptr;
       
       int rootval = preorder[preIdx];
       if (rootval <= low || rootval >= high)
         return nullptr;

       preIdx++;
    
       TreeNode* root = new TreeNode(rootval);

       root->left = build(preorder, preIdx, low, root->val);
       root->right = build(preorder, preIdx, root->val, high);

       return root;
    }
 };
/*
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preIdx = 0;
        return dfs(preorder, preIdx, INT_MAX);
    }

    TreeNode* dfs(vector<int>& preorder, int& preIdx, int bound)
    {
       int n = preorder.size();
       if (i >= n)
         return nullptr;
    
       int val = preorder[preIdx++];
       if (val > bound)
         return nullptr;
       TreeNode* node = new TreeNode(val);  // 构建的时候初始下面为 nullptr;

       //在构造左子树期间
       //我们绝对不会看到右子树的元素
       //因为右子树的元素一定在 preorder 的后面
       //也就是说：
       //当我们进入右子树递归时：
       //所有 < root->val 的值
       //已经全部被左子树“吃掉”了
       
       node->left  = dfs(preorder, preIdx, val);
       node->right = dfs(preorder, preIdx, bound);

       return node;
    }
};
*/