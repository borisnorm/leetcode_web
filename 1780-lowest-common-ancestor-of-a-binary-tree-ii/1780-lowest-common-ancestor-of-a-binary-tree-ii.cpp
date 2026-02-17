/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     bool foundP = false;
     bool foundQ = false;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
          return nullptr;
        
        TreeNode* lca = findLCA(root, p, q);

        return (foundP && foundQ) ? lca : nullptr;
                
    }

    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q){
         if (!root)
           return nullptr;
         TreeNode* left  = findLCA(root->left, p, q);
         TreeNode* right = findLCA(root->right, p, q);

         if (root == p)
         {
            foundP = true;
            return root;
         }

         if (root == q)
         {
            foundQ = true;
            return root;
         }

         
         if (left && right)
           return root;
        
        return left ? left : right;
    }
};