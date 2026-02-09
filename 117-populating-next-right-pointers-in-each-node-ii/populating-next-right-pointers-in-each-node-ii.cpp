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
        
        Node* cur = root;

        while(cur)
        {
           Node dummy(0);
           Node* tail = &dummy;

           // current layer for next layer
           while(cur)
           {
               if (cur->left)
               {
                  tail->next = cur->left;
                  tail = tail->next;
               }
               if (cur->right)
               {
                  tail->next = cur->right;
                  tail = tail->next;
               }

               cur = cur->next;
           }

           //进入到下一层, cur 在 tail 那里就已经被更新过了
           cur = dummy.next;
        }

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
            if (root->right)
              root->left->next = root->right;
            else
              root->left->next = findNext(root->next);
        }

        if (root->right)
          root->right->next = findNext(root->next);

        connect(root->right);
        connect(root->left);

        return root;
    }

    Node* findNext(Node* node)
    {
       while (node)
       {
          if (node->left)
            return node->left;
        
          if (node->right)
            return node->right;
        
          node = node->next;
       }

       return nullptr;
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