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
    int sumNumbers(TreeNode* root) {
        if (!root)
          return 0;
        
        int num = 0;
        long long res = dfs(root, num);

        return (int)res;
    }

    long long dfs(TreeNode* root, long long num)
    {
        if (!root)
          return 0;  // 如果左右子节点为空, 应该返回当前的 val

        num = num*10 + root->val;
        if (!root->left && !root->right)
          return num;
        
        int leftNum = dfs(root->left, num);
        int rightNum = dfs(root->right, num);

        return leftNum + rightNum;
    }
};

/*
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root)
          return 0;
        
        stack<pair<TreeNode*, long long>> st;
        st.push({root, 0});
    
        long long sum = 0;

        while(!st.empty())
        {
           auto [cur, num] = st.top();
           st.pop();

           num = num * 10 + cur->val;
           if (!cur->left && !cur->right)
           {
              sum += num;
           }

           if (cur->right)
             st.push({cur->right, num});
            
           if (cur->left)
             st.push({cur->left, num});
        }

        return (int)sum;
    }
};

*/


/*
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root)
          return 0;

        return sumNumbersFromRoot(root, 0);
    }

    int sumNumbersFromRoot(TreeNode* root, int val)
    {
        if (!root)
          return 0;   // 如果左右子节点为空, 应该返回当前的 val
        
        val = val * 10 + root->val;
        if (!root->left && !root->right)
          return val;

        int leftVal = sumNumbersFromRoot(root->left, val);
        int rightVal = sumNumbersFromRoot(root->right, val);

        return leftVal + rightVal;
    }
};
*/