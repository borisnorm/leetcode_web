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
    int maxPathSum(TreeNode* root) {
         if (!root)
          return INT_MIN;
         long long maxSum = LLONG_MIN;
         dfs(root, maxSum);

         return maxSum;
    }   

    long long dfs(TreeNode* root, long long& maxSum)
    {
        if (!root)
          return 0;
        
       // long long l = dfs(root->left, maxSum);
        //long long r = dfs(root->right, maxSum);
        //l = max(l, 0LL);
        //r = max(r, 0LL);
        
         //l = max(l, 0); 会报错
        //不是 0 有问题，而是 std::max 的两个参数类型不一致，模板无法推导。
        //加上 0LL（你写成 OLL，本质是 0LL）后，类型统一成 long long，编译器就开心了。
        long long l = max(dfs(root->left, maxSum), 0LL);
        long long r = max(dfs(root->right, maxSum), 0LL);

        long long sum = l + r + root->val;
        maxSum = max(maxSum, sum);

        return max(l, r) + root->val;
    }
};

/*
class Solution {
public:
    int max_sum = INT_MIN;
    int maxPathSum(TreeNode* root) {
       if (!root)
         return 0;

       nodePathSum(root);

       return max_sum;
    }

    int nodePathSum(TreeNode* node)
    {
        if (!node)
          return 0;

        int left_sum = max(nodePathSum(node->left), 0);
        int right_sum = max(nodePathSum(node->right), 0);
        
        //取最大值的逻辑
        int node_sum = left_sum + right_sum + node->val;
        max_sum = max(max_sum, node_sum);

        return max(left_sum, right_sum) + node->val;
    }
};
*/

/*
class Solution {
public:

    int maxPathSum(TreeNode* root) {
        if (!root)
          return 0;
        
        stack<TreeNode*> st;
        unordered_map<TreeNode*, int> n2sum;
        TreeNode* cur = root;
        TreeNode* last = nullptr;
        int maxSum = INT_MIN;

        while (cur || !st.empty())
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }

            TreeNode* node = st.top();
            if (!node->right || last == node->right)
            {
                int l = 0;
                if (node->left && n2sum.count(node->left))
                  l = max(0, n2sum[node->left]);
                
                int r = 0;
                if (node->right && n2sum.count(node->right))
                  r = max(0, n2sum[node->right]);
                
                maxSum = max(maxSum, l + node->val + r);

                n2sum[node] = max(l, r) + node->val;

                st.pop();
                last = node;
                cur = nullptr;
            }
            else
            {
               cur = node->right;
            }
        }
        return maxSum;
    }
};
*/

