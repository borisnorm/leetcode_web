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
    
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
          return 0;
        
        unordered_map<long long, int> prefixSum;
        prefixSum[0] = 1;
        
        return dfs(root, targetSum, 0, prefixSum);
    }

    int dfs(TreeNode* root, int targetSum, long long curSum, unordered_map<long long, int>& prefixSum)
    {
       if (!root)
         return 0;
    
       curSum += root->val;
       
       int cnt = prefixSum[curSum - targetSum];

       prefixSum[curSum]++;
       int left_cnt = dfs(root->left, targetSum, curSum, prefixSum); 
       int right_cnt = dfs(root->right, targetSum, curSum, prefixSum);
       prefixSum[curSum]--;

       return left_cnt + right_cnt + cnt;
    }
};


/*
class Solution {
public:
    
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
          return 0;

        return countPath(root, (long long)targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

    int countPath(TreeNode* node, long long targetSum)
    {
      if (!node)
        return 0;

       int cnt = (node->val == targetSum) ? 1 : 0;

       long long leftcnt = countPath(node->left, (targetSum - node->val));
       long long rightcnt = countPath(node->right, (targetSum - node->val));

       return leftcnt + rightcnt + cnt;
    }
};

*/