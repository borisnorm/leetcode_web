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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
          return nullptr;
        int n = nums.size();

        int l = 0;
        int r = n - 1;
        TreeNode* root = nullptr;
        queue<tuple<TreeNode**, int, int>> q;
        q.push({&root, l, r });
        
        while (!q.empty())
        {
            auto [nodePtr, l, r] = q.front();
            q.pop();

            int mid = l + (r-l)/2;
            
            *nodePtr = new TreeNode(nums[mid]);
            if (l <= mid-1)
            {
                q.push({&((*nodePtr)->left), l, mid-1});
            }

            if (mid+1 <= r)
            {
                q.push({&((*nodePtr)->right), mid+1, r});
            }
        }

        return root;
    }
};
/*
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
          return nullptr;
        
        int n = nums.size();
        int l = 0;
        int r = n-1;

        TreeNode* root = nullptr;
        stack<tuple<TreeNode**, int, int>> st;
        st.push({&root, l, r});

        while (!st.empty())
        {
           auto [nodePtr, l, r] = st.top();
           st.pop();

           int mid = l + (r-l)/2;

           *nodePtr = new TreeNode(nums[mid]);

           // right first, then left
           if (mid + 1 <= r)
           {
              st.push({&((*nodePtr)->right), mid+1, r});
           }

           if (l <= mid - 1)
           {
              st.push({&((*nodePtr)->left), l, mid-1});
           }
        }

        return root;
    }
};
*/

/*
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
          return nullptr;
        return buildBST(nums, 0, nums.size()-1);      
    }

    TreeNode* buildBST(vector<int>& nums, int left, int right)
    {
        if (left > right)
          return nullptr;

        int mid = left + (right-left)/2;

        //前序遍历
        TreeNode* node = new TreeNode(nums[mid]);

        node->left  = buildBST(nums, left, mid-1);
        node->right = buildBST(nums, mid+1, right);
          
       return node;      
    }
};
*/