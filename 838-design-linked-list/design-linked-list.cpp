class MyLinkedList {
public:

    struct Node{
      int val;
      Node* prev;
      Node* next;
      Node(int v):val(v), prev(nullptr), next(nullptr){}
    };

    Node* dummy_head;
    Node* dummy_tail;
    int sz;

    Node* getNode(int idx)
    {
      Node* cur = dummy_head->next;
      for (int i = 0; i < idx; i++)
        cur = cur->next;
      return cur;
    }

    MyLinkedList() {
      dummy_head = new Node(0);
      dummy_tail = new Node(0);
      dummy_head->next = dummy_tail;
      dummy_tail->prev = dummy_head;
      sz = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= sz)
          return -1;
        return getNode(index)->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(sz, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > sz)
          return;

        //succ 后继就是当前 idx
        Node* succ = (index == sz) ? dummy_tail : getNode(index);
        Node* pred = succ->prev;

        Node* node = new Node(val);

        node->prev = pred;
        node->next = succ;

        pred->next = node;
        succ->prev = node;
        sz++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= sz)
          return;
        
        Node* cur = getNode(index);
        Node* pred = cur->prev;
        Node* succ = cur->next;

        pred->next = succ;
        succ->prev = pred;
        delete cur;
        sz--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */