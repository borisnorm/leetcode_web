/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
          if (!(p && q))
            return nullptr;
        
          Node* cur_p = p;
          Node* cur_q = q;
          
          while (cur_p != cur_q)
          {
              cur_p = cur_p ? cur_p->parent : q;
              cur_q = cur_q ? cur_q->parent : p;
          }

          return cur_p;
    }
};