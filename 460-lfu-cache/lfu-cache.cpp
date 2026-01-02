class LFUCache {
public:
    
    int capacity;
    int minFreq;

    // key -->  {val, freq}
    unordered_map<int, pair<int, int>> key2val;

    // freq- > key list
    unordered_map<int, list<int>> freq2keys;

    // key --> iterator in freq2keys
    unordered_map<int, list<int>::iterator> key2iter;

    void increaseFreq(int key)
    {
       int val = key2val[key].first;
       int freq = key2val[key].second;

       freq2keys[freq].erase(key2iter[key]);
       if (freq2keys[freq].empty())
       {
          freq2keys.erase(freq);
          if (minFreq == freq)
            minFreq++;
       }

       int newFreq = freq + 1;
       freq2keys[newFreq].push_back(key);
       key2iter[key] = prev(freq2keys[newFreq].end());
       key2val[key] = {val, newFreq};
    }

    void removeLFU()
    {
      int key = freq2keys[minFreq].front();

      freq2keys[minFreq].pop_front();
      if (freq2keys[minFreq].empty())
      {
         freq2keys.erase(minFreq);
      }

      key2iter.erase(key);
      key2val.erase(key);
    }
    // Least farest update
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }
    
    int get(int key) {
        if (key2val.find(key) == key2val.end())
          return -1;

        increaseFreq(key);
        return key2val[key].first;
    }
    
    void put(int key, int value) {
        if (capacity <=0 )
          return;

        if (key2val.find(key) != key2val.end())
        {
            key2val[key].first = value;
            increaseFreq(key);
            return;
        }

        if (key2val.size() >= capacity)
          removeLFU();

        int freq = 1;
        key2val[key].first = value;
        key2val[key].second = freq;
        freq2keys[freq].push_back(key);
        key2iter[key] = prev(freq2keys[freq].end());
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */