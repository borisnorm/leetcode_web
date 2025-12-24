class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> kv;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        kv[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        
        if (!kv.count(key))
          return "";

        auto it = kv.find(key);
        //vector<pair<string, int>> vals;
        auto& vals = it->second;
    
        int l = 0;
        int r = vals.size();

        while (l < r)
        {
          int mid = l + (r-l)/2;
          
          if (vals[mid].second <= timestamp)
            l = mid + 1;
          else
            r = mid;
        }   

        if (l < 1)
          return "";

        return vals[l-1].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */