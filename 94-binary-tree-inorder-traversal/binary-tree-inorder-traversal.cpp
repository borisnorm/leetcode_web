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
    vector<int> inorderTraversal(TreeNode* root) {
        // left root right
        if (!root)
          return {};
        
        stack<TreeNode*> st;
        vector<int> nums;
        
        TreeNode* cur = root;
        while (cur || !st.empty())
        {
            while (cur)
            {
               st.push(cur);
               cur = cur->left;
            }
            
            // 此时的 cur 已经是 nullptr 了
            cur = st.top();
            st.pop();

            nums.push_back(cur->val);

            cur = cur->right;
            //if (node->right)
            //  st.push(node->right);
        }

        return nums;
    }
};
/*

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
         if (!root)
           return {};
         vector<int> res;

         inorderTraverse(root, res);
         return res;
    }

    void inorderTraverse(TreeNode* root, vector<int>& nums)
    {
        if (!root)
          return;

        // left root right

        inorderTraverse(root->left, nums);

        nums.push_back(root->val);

        inorderTraverse(root->right, nums);
    }
};

*/