class LRUCache {
    int capacity;
    list<pair<int, int>> kvl;
    unordered_map<int, list<pair<int, int>>::iterator> key2it; 
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!key2it.count(key))
          return -1;
        
        auto it = key2it[key];
        int val = it->second;
        updateLRUentry(key, val);

        return val;
    }
    
    void put(int key, int value) {
        
        if (!key2it.count(key) && kvl.size() == capacity)
          removeLRUentry();
        
        updateLRUentry(key, value);
    }

    void updateLRUentry(int key, int val)
    {
       if (key2it.count(key))
       {
          auto it = key2it[key];
          kvl.erase(it);
       }

       kvl.push_front({key, val});
       auto it = kvl.begin();
       key2it[key] = it;
    }
    
    void removeLRUentry()
    {
       auto it = prev(kvl.end());

       int key = it->first;
       key2it.erase(key);

       kvl.pop_back();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */