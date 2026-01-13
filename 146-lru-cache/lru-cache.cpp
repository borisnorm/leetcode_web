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

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */