/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
         // pivot
         // head < x < pivot, insert before pivot
         // x > pivot(node), insret after the pivot (1)take over the next link or (2) link back to header  
         if (!head)
         {
            head = new Node(insertVal);
            head->next = head;
            return head;
         }

         // minDiff = min(mindiff, (insertVal - node->val));
         // prev < insertVal < nxtVal

         Node* cur = head;
         Node* nxt = nullptr;

         while (true)
         {
            nxt = cur->next;

            if (cur->val <= nxt->val)
            {
              if (cur->val <= insertVal && insertVal <= nxt->val)
              {
                Node* newNode = new Node(insertVal);
                cur->next = newNode;
                newNode->next = nxt;

                break;
              }
            }
            else  // cur->val > nxt->val
            { 
              //if ( cur->val <= insertVal || insertVal <= nxt->val)
              // ä¸¤ç§å¯è½æ§,  4--> 1, å¯ä»¥æå¥ 5, ææ¯ 1
              if (insertVal >= cur->val || insertVal <= nxt->val)
              {
                Node* newNode = new Node(insertVal);
                cur->next = newNode;
                newNode->next = nxt;

                break;
              }
            }

            cur = nxt;       
                   
            if (cur == head)
            {
               Node* newNode = new Node(insertVal);
               newNode->next = head->next;
               head->next = newNode;
              break;
            }
         }


         return head;       
    }
};