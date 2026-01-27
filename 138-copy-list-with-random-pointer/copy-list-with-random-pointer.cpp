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
        
        Node dummy(0);
        Node* cur_cpy = &dummy;

        Node* cur = head;

        unordered_map<Node*, Node*> origin2cpy;
        while(cur)
        {
           cur_cpy->next = new Node(cur->val);
           cur_cpy = cur_cpy->next;

           // cur_cpy 已经从 dummy 跳到了 cur_cpy 上
           origin2cpy[cur] = cur_cpy;

           cur = cur->next;
        }

        cur = head;
        cur_cpy = dummy.next;
        while(cur)
        {
           Node* random = cur->random;

           cur_cpy->random = origin2cpy[random];

           cur_cpy = cur_cpy->next;
           cur = cur->next;
        }

        return dummy.next;
        
    }
};
/*
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
    
         // 1. 先让 copy 成链
         // 2. 再让 cur->cpy 成 map 为 random 做准备 
         while (tail)
         {
            tail_cpy->next = new Node(tail->val);
            tail_cpy = tail_cpy->next;

            node_cpy_map[tail] = tail_cpy;
         
            tail = tail->next;
         }

         tail = head;
         tail_cpy = dummy_cpy_head->next;

         // tail 作为key copy构建 random
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

*/