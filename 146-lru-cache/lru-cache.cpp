class LRUCache {
private:
    int cap;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> l;

public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        // 将 key 变为最近使用
        makeRecently(key);
        return cache[key].first;
    }

    void put(int key, int val) {
        if (cache.find(key) != cache.end()) {
            // 修改 key 的值
            l.erase(cache[key].second);
        } else {
            if (l.size() >= this->cap) {
                // 链表头部就是最久未使用的 key
                cache.erase(l.front());
                l.pop_front();
            }
        }
        // 将新的 key 添加链表尾部
        l.push_back(key);
        cache[key] = {val, prev(l.end())};
    }

    void makeRecently(int key) {
        int val = cache[key].first;
        // 删除 key，重新插入到队尾
        l.erase(cache[key].second);
        l.push_back(key);
        cache[key] = {val, prev(l.end())};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */