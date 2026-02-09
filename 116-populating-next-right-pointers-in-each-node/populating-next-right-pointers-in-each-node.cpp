/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
          return nullptr;

        //same parent
        if (root->left && root->right)
          root->left->next = root->right;
        
        //different parent
        if (root->right && root->next)
          root->right->next = root->next->left;
        
        connect(root->left);
        connect(root->right);

        return root;
    }
};
/*
class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
          return nullptr;
        
        if (root->left)
        {
           Node* cur = root->left;

           //same parent
           root->left->next = root->right;

           //different parent
           if (root->next)
             root->right->next = root->next->left;
        }

        connect(root->left);
        connect(root->right);

        return root;
    }
};
*/
/*
class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
          return nullptr;
        
        Node* leftmost = root;
        
        //本层 为 下一层 生成 next 链接
        //本层（父节点层）负责为「下一层（子节点层）」生成完整的 next 链。
        //所以要事先检查 下一层是否存在, 不存在就 没有必要继续了
        while(leftmost->left)
        {
           //从本层最左节点开始, 不断 next, 构建 下一层的 next 链接
           Node* cur = leftmost;
           while (cur)
           {
              //perfect tree 的 left 与 right 都是 存在的所以不用检查

              // the same parent
              cur->left->next = cur->right;

              // different parent
              if (cur->next)
                cur->right->next = cur->next->left;

              // next sibling
              cur = cur->next;
           }
           // come back to the leftmost and to next left
           leftmost = leftmost->left;
        }
        return root;
    }
};

*/

/*
class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
          return nullptr;
        
        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
           int q_sz = q.size();
           Node* pre = nullptr; 
           for (int i = 0; i < q_sz; i++)
           {
              Node* cur = q.front();
              q.pop();

              if (pre)
              {
                pre->next = cur;
                //cur->next = nullptr;
              }

              pre = cur;
            
              if (cur->left)
                q.push(cur->left);
              
              if (cur->right)
                q.push(cur->right);
           }
        }

        return root;
    }
};

*/