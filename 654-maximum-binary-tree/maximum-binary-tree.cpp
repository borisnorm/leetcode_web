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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 0)
           return nullptr;
        
        TreeNode* root = buildTree(nums, 0, n-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& nums, int l, int r)
    {
        if (l > r)
          return nullptr;
        
          //maxValPos = root
          //left =  [0, root-1] 
          //right = [root + 1, n-1]

          int maxValPos = 0;
          int maxVal = INT_MIN;
          for (int i = l; i <= r; i++)
          {
              if (nums[i] > maxVal)
              {
                  maxVal = nums[i];
                  maxValPos = i;
              }
          }

          int rootVal = nums[maxValPos];
          int rootIdx = maxValPos;
          TreeNode* node = new TreeNode(rootVal);

          int leftIdx = rootIdx - 1;
          node->left = buildTree(nums, l, leftIdx);
        
          int rightIdx = rootIdx + 1;
          node->right = buildTree(nums, rightIdx, r);
          
          return node;
    }


};