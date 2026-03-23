/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root)
          return root;
          
        Node* head = nullptr;
        Node* prev = nullptr;

        inorder(root, head, prev);

        head->left = prev;
        prev->right = head;

        return head;    
    }

    void inorder(Node* node, Node*& head, Node*& prev)
    {
        if (!node)
          return;
    
        inorder(node->left, head, prev);

        if (!prev)
          head = node;
        else
        {
           prev->right = node;
           node->left = prev;
        }

        prev = node;

        inorder(node->right, head, prev);
    }
};