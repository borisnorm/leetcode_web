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
/*
class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
          return nullptr;
        
        Node* leftmost = root;
        
        while(leftmost->left)
        {
           Node* cur = leftmost;
           while (cur)
           {
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