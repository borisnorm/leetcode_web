/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
          return head;

        ListNode  dummy(0);
        ListNode* dummy_head = &dummy;
        dummy_head->next = head;
        // cur not change, pre not change
        // nxt change

        //ListNode* pre = nullptr;  // pre 要进行指向 next, 所以不能为 nullptr;
        ListNode* pre = dummy_head;
        ListNode* cur = head;    // not change
        ListNode* nxt = nullptr;

        while(cur->next)
        {
           nxt = cur->next;
           
           // cur 不动, 但 nxt 移动后,  cur->next 旧空了, 需要立即补上
           // 要检查 nxt(cur->next) 是否合法, 否则 nxt->next 直接报错 UB, undefined behavior
           cur->next = nxt->next;

            // 这里一定要是 pre->next 不能是 cur, 否则逻辑全乱了
           nxt->next = pre->next;   

           // 保证 pre 不动
           pre->next = nxt;
        }

        return dummy.next;
    }
    
/*
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
          return head;

        //  尾插法, pre 要初始化为 nullptr,  把旧节点从 list 拆下来,  放到新的 尾部

        //  node_0 --> node_1 --> node_2 --> nullptr;
        //  ----------------------------------
        //  cur(node_0)-> pre              新链
        //                [nullptr];
        
        // node_1 --> node_2 --> nullptr;  当前链
        // cur = nxt;

        // --------------------------------------
        // node_1 -->nullptr
        // pre       (previous pre)

        //  cur-> pre[tail]->nullptr     搬运过程

        // -------------------------
        //                  [tail] 
        //  cur(node_1) - > node_0 -> nullptr  新链
        //  node_2 --> nullptr;                旧链                  
        //  [nxt]

        // 时间 O(n) n indicates the number of nodes
        // 空间 O(1)
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* nxt = nullptr;

        while (cur)
        {
           nxt = cur->next;
           
           cur->next = pre;
           pre = cur;

           cur = nxt;
        }

        return pre;
    }


    */

};