/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}
    Node(int _val) : val(_val), next(nullptr) {}
    Node(int _val, Node* _next) : val(_val), next(_next) {}
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        // ç©ºè¡¨ï¼æ°å»ºä¸ä¸ªèªç¯èç¹
        if (!head) {
            Node* node = new Node(insertVal);
            node->next = node;
            return node;
        }

        Node* cur = head;
        while (true) {
            Node* nxt = cur->next;

            // Case 1: æ­£å¸¸éå¢æ®µ
            if (cur->val <= nxt->val) {
                if (cur->val <= insertVal && insertVal <= nxt->val) {
                    break;
                }
            }
            // Case 2: æç¹ï¼æå¤§->æå°ï¼
            else { // cur->val > nxt->val
                if (insertVal >= cur->val || insertVal <= nxt->val) {
                    break;
                }
            }

            cur = cur->next;

            // è½¬äºä¸åè¿æ²¡æï¼æ¯å¦å¨ç¸ç­
            if (cur == head) {
                break;
            }
        }

        Node* node = new Node(insertVal);
        node->next = cur->next;
        cur->next = node;
        return head;
    }
};
