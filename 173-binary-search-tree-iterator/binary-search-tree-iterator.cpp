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
class BSTIterator {

    stack<TreeNode*> st;
public:
    void pushLeft(TreeNode* node)
    {
       //一次返回一个最小值
       //用一个栈，模拟递归中序遍历的“调用栈”
       //栈顶元素：当前最小的未访问节点
       // top of the stack is the smallest number;
       while (node)
       {
         st.push(node);
         node = node->left; 
       } 
    }

    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
       TreeNode* node = st.top();
       st.pop();

       if (node->right)
         pushLeft(node->right);
     
       return node->val;
    }
    
    bool hasNext() {
       return st.empty() ? false : true;;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */