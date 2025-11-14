/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
         if (!head)
           return head;

         //Node dummy(0);
         //Node* dummy_head = &dummy;
         //dummy_head->next = head;
         Node* tail = head;

         Node  dummy_cpy(0);
         Node* dummy_cpy_head = &dummy_cpy;
         Node* tail_cpy = dummy_cpy_head;

         unordered_map<Node*, Node*> node_cpy_map;
    
         while (tail)
         {
            tail_cpy->next = new Node(tail->val);
            tail_cpy = tail_cpy->next;

            node_cpy_map[tail] = tail_cpy;
         
            tail = tail->next;
         }

         tail = head;
         tail_cpy = dummy_cpy_head->next;

         while (tail)
         {
            Node* neighbor = tail->random;

            tail_cpy->random = node_cpy_map[neighbor];

            tail = tail->next;
            tail_cpy = tail_cpy->next;
         } 


         return dummy_cpy_head->next;
    }
};