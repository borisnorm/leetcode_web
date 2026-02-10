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
//https://claude.ai/chat/605c88a0-62f1-425a-888e-4d0a0935fbf9
class Solution {
public:
    TreeNode* prev = nullptr;  // 全局指针，记录上一个访问的节点
    
    void flatten(TreeNode* root) {
        if (!root) return;  // 空节点直接返回
        
        // 前序遍历顺序：根 → 左 → 右
        
        // 1. 先处理当前节点（根）
        if (prev) {  // 如果有前驱节点
            prev->right = root;  // 前驱的right指向当前节点
            prev->left = nullptr;  // 前驱的left置空
        }
        prev = root;  // 更新prev为当前节点
        
        // 2. 保存左右子树（因为修改会破坏原结构）
        TreeNode* left = root->left;  // 保存左子树指针
        TreeNode* right = root->right;  // 保存右子树指针
        
        // 3. 递归处理左子树
        flatten(left);
        
        // 4. 递归处理右子树
        flatten(right);
    }
};
/*
class Solution {
public:
    TreeNode* prev = nullptr;
    void flatten(TreeNode* root) {
        if (!root)
          return;
        
        flatten(root->right);
        flatten(root->left);
       
        root->right = prev;
        root->left   = nullptr;

        prev = root;
    }
};
*/

/*
 class Solution {
public:

    void flatten(TreeNode* root) {
        if (!root)
          return;
        
        TreeNode* cur = root;
        while (cur)
        {
            TreeNode* prev = cur;
            if (prev->left)
            {
                //进入左端
                prev = prev->left;
                //进入左端的最右端
                while (prev->right)
                   prev = prev->right;

                //左端的最右端 链接 当前节点的右端
                prev->right = cur->right;

                //当前节点的右端 链接 当前节点的左端
                cur->right = cur->left;

                //当前节点的左端设置为 null
                cur->left = nullptr;
            }

            cur = cur->right;
        }
    }
 };
 */
/* 
class Solution {
public:

    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);

        TreeNode* prev = nullptr;
        while (!st.empty())
        {
           TreeNode* cur = st.top();
           st.pop();

           if (prev)
           {
             prev->right = cur;
             prev->left = nullptr;
           }

           if (cur && cur->right)
            st.push(cur->right);
        
           if (cur && cur->left)
             st.push(cur->left);

           prev = cur;
        }
    }
};
*/

