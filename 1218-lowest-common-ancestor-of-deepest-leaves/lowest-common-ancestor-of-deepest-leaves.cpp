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
 int getDepth(TreeNode* root, TreeNode** lca) {
    if (!root) return 0;

    TreeNode* l_lca = root;
    TreeNode* r_lca = root;

    int ld = getDepth(root->left,  &l_lca);
    int rd = getDepth(root->right, &r_lca);

    if (ld == rd) {
        *lca = root;
    } else if (ld > rd) {
        *lca = l_lca;
    } else {
        *lca = r_lca;
    }

    return max(ld, rd) + 1;
}

TreeNode* lcaDeepestLeaves(TreeNode* root) {
    TreeNode* ans = nullptr;
    getDepth(root, &ans);
    return ans;
}
};

/*
class Solution {
public:
struct NodeDepth{
    TreeNode* pre;
    int depth;
};

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root)
          return nullptr;

        TreeNode* lca = root;
        getDepth(root, lca);

        return lca;
    }


    int getDepth(TreeNode* root, TreeNode* lca)
    {
        if (!root)
          return 0;
        
        int maxDepth = 0;
        TreeNode* l_lca = root;
        TreeNode* r_lca = root;

        int leftDepth = getDepth(root->left, l_lca);
        int rightDepth = getDepth(root->right, r_lca);

        if (leftDepth > rightDepth)
        {
          maxDepth = leftDepth;
          lca = l_lca;
        }
        else if (leftDepth < rightDepth)
        {
           maxDepth = rightDepth;
           lca = r_lca;
        }
        else
        {
           maxDepth = leftDepth;
           lca = root;
        }

        return maxDepth + 1;
    }
};
*/