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
class CBTInserter {
public:
    TreeNode* _root;
    queue<TreeNode*> node_queue;
    CBTInserter(TreeNode* root) { 
       this->_root = root;

       queue<TreeNode*> tmp;

       if (root)
         tmp.push(root);

       while (!tmp.empty())
       {
          TreeNode* node = tmp.front();
          tmp.pop();

          if (node->left)
            tmp.push(node->left);
          if (node->right)
            tmp.push(node->right);
        
          if (!(node->left && node->right))
            node_queue.push(node);
       }
    }
    
    int insert(int val) {
      TreeNode* node = new TreeNode(val);
      TreeNode* parent = node_queue.front();
      
      if (!parent->left)
        parent->left = node;
      else
      {
        parent->right = node;
        node_queue.pop();
      }

      node_queue.push(node);
      return parent->val;
    }
    
    TreeNode* get_root() {
       return _root; 
    }
};


/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */