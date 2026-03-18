/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head || (!head->next && !head->child))
          return head;

        Node* cur = head;
        Node* nxt = nullptr;
        Node* cur_child = nullptr;
        while(cur)
        {
           if (!cur->child)
           {
              cur = cur->next;
              continue;
           }
          
           nxt = cur->next;
           cur_child = cur->child;

          // cur -> child
          cur->next = cur->child;
          cur->child->prev = cur;
          
           /* child tail */
           while (cur_child->next)
             cur_child = cur_child->next;
          
          /* tail -> nxt */
          cur_child->next = nxt;
          if (nxt)
            nxt->prev = cur_child;



          cur->child = nullptr;
        }
        return head;
    }
};