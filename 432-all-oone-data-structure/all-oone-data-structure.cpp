class AllOne {
private:
    
    struct Node{
        int cnt;
        unordered_set<string> keys;
        Node *prev;
        Node *next;
        Node(int c) : cnt(c), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    
    unordered_map<string, Node*> key2node;
 
    // node -> newNode
    // node <- newNode
    void insertAfter(Node* node, Node* newNode)
    {
       Node* nxt = node->next;

       newNode->prev = node;
       newNode->next = nxt;

       nxt->prev  = newNode;
       node->next = newNode;
    }
   
    // newNode -> node
    // newNode <- node
    void insertBefore(Node* node, Node* newNode)
    {
       Node* pre = node->prev;

       newNode->next = node;
       newNode->prev = pre;

       pre->next = newNode;
       node->prev = newNode;
    }

    void removeNode(Node* node)
    {
       Node* pre = node->prev;
       Node* nxt = node->next;
      
       pre->next = nxt;
       nxt->prev = pre;

       delete node;
    }

public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
       
        // head -> tail
        // head <- tail
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
    
       // key was not found
       if (key2node.find(key) == key2node.end())
       {
         Node* first = head->next;
         if (first != tail && first->cnt == 1)
         {
            first->keys.insert(key);
            key2node[key] = first;
         }
         else
         {
            Node* newNode = new Node(1);
            newNode->keys.insert(key);
            insertAfter(head, newNode);
            key2node[key] = newNode;
         }
         return;
       }

       Node* cur = key2node[key];
       int cnt = cur->cnt;
       Node* nxt = cur->next;

       cur->keys.erase(key);

       if (nxt != tail && nxt->cnt == cnt + 1)
       {
          nxt->keys.insert(key);
          key2node[key] = nxt;
       }
       else
       {
          Node* newNode = new Node(cnt+1);
          newNode->keys.insert(key);
          insertAfter(cur, newNode);
          key2node[key] = newNode;
       }

       if (cur->keys.empty())
         removeNode(cur);
    }
    
    void dec(string key) {
      auto it = key2node.find(key);
      if (it == key2node.end())
        return;

      Node* cur = it->second;
      int cnt = cur->cnt;
      Node* prv = cur->prev;

      cur->keys.erase(key);

      if (cnt == 1)
        key2node.erase(key);
      else
      {
         if (prv != head && prv->cnt == cnt -1)
         {
              prv->keys.insert(key);
              key2node[key] = prv;
         }
         else
         {
             Node* newNode = new Node(cnt - 1);
             newNode->keys.insert(key);
             insertBefore(cur, newNode);
             key2node[key] = newNode;
         }
      }

      if (cur->keys.empty())
        removeNode(cur);
    }
    
    string getMaxKey() {
        if (head->next == tail)
          return "";
        Node* maxNode = tail->prev;
        if (maxNode->keys.empty())
          return "";
        
        return *(maxNode->keys.begin());
    }
    
    string getMinKey() {
        if (head->next == tail)
          return "";
        Node* minNode = head->next;
        if (minNode->keys.empty())
          return "";
        
        return *(minNode->keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */