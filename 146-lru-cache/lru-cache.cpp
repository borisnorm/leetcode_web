

class LRUCache {
public:

    struct Node{
      int key;
      int val;
      Node *prev;
      Node *next;
      Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int cap;

    Node* head;
    Node* tail;
    unordered_map<int, Node*> key2node;


    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
       
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!key2node.count(key))
          return -1;
        
        Node* node = key2node[key];
        int val = node->val;
        updateLRUentry(node);
        return val;
    }
    
    void put(int key, int value) {
        if (!key2node.count(key) && key2node.size() == cap)
          removeLRUentry();

        if (key2node.count(key))
        {
            Node* node = key2node[key];
            node->val = value;
            updateLRUentry(node);
        }
        else
        {
            Node* node = new Node(key, value);
            key2node[key] = node;
            add2Head(node);
        }
         
    }

    void add2Head(Node* node)
    {
        Node* nxt = head->next;

        head->next = node;
        node->prev = head;

        node->next = nxt;
        nxt->prev  = node;
    }

    void removeNode(Node* node)
    {
       Node* prev = node->prev;
       Node* nxt  = node->next;

       prev->next = nxt;
       nxt->prev  = prev;
    }

   
    void updateLRUentry(Node* node)
    {
        //remove node
        removeNode(node);

        //add to headd
        add2Head(node);
    }

    void removeLRUentry()
    {
        Node* node = tail->prev;
        removeNode(node);
    
        key2node.erase(node->key);

        delete node;
    }
};

/*
class LRUCache {
public:
    int cap;
 
    list<pair<int, int>> kvl;
    unordered_map<int, list<pair<int, int>>::iterator > key2it;

    LRUCache(int capacity) {
       cap = capacity;
    }
    
    int get(int key) {
        if (!key2it.count(key))
          return -1;
        
        auto it =key2it[key];
        int val = it->second;

        updateLRUentry(key, val);

        return val;
    }
    
    void put(int key, int value) {
        if (!key2it.count(key) && kvl.size() == cap)
        {
          removeLRUentry();
        }

        updateLRUentry(key, value);
    }

    void updateLRUentry(int key, int val)
    {
        // delete it from list if found
        if (key2it.count(key))
        {
            kvl.erase(key2it[key]);
        }

        // add it to front of list
        kvl.push_front({key, val});

        // update it of key2it
        key2it[key] = kvl.begin();
    }

    void removeLRUentry()
    {
        // find the last one it and key in kvl
        auto it = prev(kvl.end());

        // delete it from kv2it with key
        key2it.erase(it->first);

        // delete it from the end;
        kvl.pop_back();
    }
};
*/


/*
class LRUCache {
    int capacity;
    list<pair<int, int>> kvl;

    // list 的 iterator 是那个 pair <int, int>
    unordered_map<int, list<pair<int, int>>::iterator> key2it; 
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!key2it.count(key))
          return -1;

        int val = key2it[key]->second;
        updateLRUentry(key, val);

        return val;
    }
    
    void put(int key, int value) {
        
        // key 不在 kv iter map 里面, 且 kvl 达到它的上限
        if (!key2it.count(key) && kvl.size() == capacity)
          removeLRUentry();
        
        // 如果 key 存在, 就更新 这个 key with this value
        updateLRUentry(key, value);
    }

    void updateLRUentry(int key, int val)
    {
       //delete it from the list
       if (key2it.count(key))
       {
          auto it = key2it[key];
          kvl.erase(it);
       }

       // add it to front
       kvl.push_front({key, val});

       // update it kv 
       key2it[key] = kvl.begin();
    }
    
    void removeLRUentry()
    {
       // 找到最后一个元素, kvl.end是 最后元素的下一个元素, 是空的
       auto it = prev(kvl.end());

       // 根据 key 在  key2it 中进行删除
       int key = it->first;
       key2it.erase(key);

       // pop掉最尾端 least visted 的 entry
       kvl.pop_back();
    }
};

*/
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */