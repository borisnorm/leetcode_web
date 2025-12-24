class MyHashMap {
public:
    
    unordered_map<int, int> kv;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        
        if (!kv.count(key))
        {
            kv[key] = value;
            return;
        }

        auto it = kv.find(key);
        it->second = value;
    }
    
    int get(int key) {
        if (!kv.count(key))
          return -1;
        
        return kv[key];
    }
    
    void remove(int key) {
        if (!kv.count(key))
          return;
        
        kv.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */