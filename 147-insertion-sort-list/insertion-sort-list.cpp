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

  ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
          return head;
        
        ListNode dummy(0);
        ListNode* dummy_head = &dummy;
        
        ListNode* pre_sorted = dummy_head;
        ListNode* cur_sorted = nullptr;

        ListNode* cur = head;
        ListNode* nxt = nullptr;
        while(cur)
        {
           nxt = cur->next;
           cur->next = nullptr;

           pre_sorted = dummy_head;
           cur_sorted = dummy_head->next;

           while (cur_sorted && cur_sorted->val < cur->val)
           {
             pre_sorted = cur_sorted;
             cur_sorted = cur_sorted->next;
           }

           pre_sorted->next = cur;
           cur->next = cur_sorted;

           cur = nxt;
        }

        return dummy.next;
  }
};

/*
class Solution {
public:

ListNode* insertionSortList(ListNode* head) {
    if (!head || !head->next)
      return head;
    

    ListNode dummy(0);
    //ListNode* dummy_head = &dummy;
    //dummy_head->next = head;

    ListNode* cur = head;
    while (cur)
    {
       ListNode* nxt = cur->next;
       cur->next = nullptr;
       
       ListNode* pre = &dummy;
       while (pre->next && pre->next->val < cur->val)
         pre = pre->next;
    
       cur->next = pre->next;
       pre->next = cur;

       cur = nxt;
    }

    return dummy.next;
}
};
*/
   /*
    ListNode* insertionSortList(ListNode* head) {
            if (!head || !head->next)
              return head;

            ListNode dummy(0);
            ListNode *dummy_head = &dummy;
            dummy_head->next = head;

            ListNode* tailSorted = head; 
            ListNode* curHead = head->next;

            //init
            tailSorted->next = nullptr;

            while (curHead)
            {
               ListNode* nxt = curHead->next;
               
               ListNode* preSorted = dummy_head;
               ListNode* curSorted = dummy_head->next;

               while (curSorted)
               {
                  ListNode* nxtSorted = curSorted->next;
                  if (curHead->val < curSorted->val)
                  {
                      curHead->next = curSorted;
                      preSorted->next = curHead;
                      break;
                  }
                  else if (!nxtSorted)
                  {
                     curSorted->next = curHead;
                     tailSorted = curSorted->next;
                     tailSorted->next = nxtSorted;
                     break;
                  }

                  preSorted = curSorted;
                  curSorted = curSorted->next;
               }

               curHead = nxt;
            }

            return dummy.next;      
    }
    */
