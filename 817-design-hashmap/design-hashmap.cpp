class MyHashMap {
public:
    
    int const BUCKETS_BASE = 769;
    vector<vector<pair<int, int>>> kv_buckets;

    int hash_key(int key)
    {
       return key % BUCKETS_BASE;
    }

    MyHashMap() {
        kv_buckets.resize(BUCKETS_BASE);
    }
    
    void put(int key, int value) {
         int bucket_idx = hash_key(key);
         auto& bucket = kv_buckets[bucket_idx];

         for (auto& it: bucket)
         {
            if (it.first == key)
            {
              it.second = value;
              return;
            }
         }

         bucket.push_back({key, value});
    }
    
    int get(int key) {
         int bucket_idx = hash_key(key);
         auto& bucket = kv_buckets[bucket_idx];
        
         for (auto& it: bucket)
         {
            if (it.first == key)
            {
               return it.second;
            }
         }

         return -1;
    }
    
    void remove(int key) {
        int bucket_idx = hash_key(key);
        auto& bucket = kv_buckets[bucket_idx];
         for (auto& it: bucket)
         {
            if (it.first == key)
            {
               auto last = bucket.back();

               it.first = last.first;
               it.second = last.second;
               bucket.pop_back();

               return;
            }
         }

    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */